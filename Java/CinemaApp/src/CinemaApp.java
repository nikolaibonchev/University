import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.image.BufferedImage;
import java.io.File;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class CinemaApp extends JFrame {

    // Цветова палитра според дизайна
    private static final Color BG_COLOR = Color.BLACK;
    private static final Color TEXT_COLOR = Color.WHITE;
    private static final Color ACCENT_COLOR = new Color(127, 0, 255); // Оранжево
    private static final Color FREE_SEAT_COLOR = new Color(50, 50, 50);
    private static final Color SELECTED_SEAT_COLOR = ACCENT_COLOR;
    private static final Color TAKEN_SEAT_COLOR = new Color(80, 25, 25); // Тъмночервено за заетите места

    private static final int POSTER_WIDTH = 180;
    private static final int POSTER_HEIGHT = 260;

    private JPanel cardPanel;
    private CardLayout cardLayout;
    private NavButton onScreenBtn, soonBtn, pricesBtn;

    public CinemaApp() {
        setTitle("CinemaBests");
        setSize(950, 700);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        getContentPane().setBackground(BG_COLOR);
        setLayout(new BorderLayout());

        setExtendedState(JFrame.MAXIMIZED_BOTH);

        getContentPane().setBackground(BG_COLOR);
        setLayout(new BorderLayout());

        // 1. Създаваме празни списъци
        List<Movie> nowMovies = new ArrayList<>();
        List<Movie> comingSoonMovies = new ArrayList<>();

        // 2. Пълним ги от CSV файла (без библиотеки!)
        loadMoviesFromCSV("movies.csv", nowMovies, comingSoonMovies);

        // Горна навигация
        add(createNavBar(), BorderLayout.NORTH);

        // Основен панел за екраните
        cardLayout = new CardLayout();
        cardPanel = new JPanel(cardLayout);
        cardPanel.setBackground(BG_COLOR);

        cardPanel.add(createMovieGridPanel(nowMovies, true), "ON_SCREEN");
        cardPanel.add(createMovieGridPanel(comingSoonMovies, false), "SOON");
        cardPanel.add(createPricesPanel(), "PRICES");

        add(cardPanel, BorderLayout.CENTER);
    }

    // Създаване на персонализираното меню
    private JPanel createNavBar() {
        JPanel navPanel = new JPanel(new FlowLayout(FlowLayout.CENTER, 20, 20));
        navPanel.setBackground(BG_COLOR);

        onScreenBtn = new NavButton("ON SCREEN", true);
        soonBtn = new NavButton("SOON", false);
        pricesBtn = new NavButton("PRICES", false);

        onScreenBtn.addActionListener(e -> switchTab("ON_SCREEN", onScreenBtn));
        soonBtn.addActionListener(e -> switchTab("SOON", soonBtn));
        pricesBtn.addActionListener(e -> switchTab("PRICES", pricesBtn));

        navPanel.add(onScreenBtn);
        navPanel.add(soonBtn);
        navPanel.add(pricesBtn);

        return navPanel;
    }

    private void switchTab(String cardName, NavButton activeBtn) {
        cardLayout.show(cardPanel, cardName);
        onScreenBtn.setActive(false);
        soonBtn.setActive(false);
        pricesBtn.setActive(false);
        activeBtn.setActive(true);
    }

    // Универсален изглед за филми (На екран / Скоро)
    private JPanel createMovieGridPanel(List<Movie> movies, boolean isOnScreen) {
        JPanel mainPanel = new JPanel(new BorderLayout());
        mainPanel.setBackground(BG_COLOR);
        mainPanel.setBorder(new EmptyBorder(40, 40, 40, 40));

        JPanel gridPanel = new JPanel(new FlowLayout(FlowLayout.CENTER, 30, 20));
        gridPanel.setBackground(BG_COLOR);

        for (Movie movie : movies) {
            JPanel card = new JPanel();
            card.setLayout(new BoxLayout(card, BoxLayout.Y_AXIS));
            card.setBackground(BG_COLOR);

            // Постер с оранжева заоблена рамка
            RoundedPosterPanel posterPanel = new RoundedPosterPanel(
                    loadPosterIcon(movie.posterFileName, movie.title, POSTER_WIDTH, POSTER_HEIGHT)
            );
            posterPanel.setAlignmentX(Component.CENTER_ALIGNMENT);
            posterPanel.setCursor(new Cursor(Cursor.HAND_CURSOR));

            if (isOnScreen) {
                posterPanel.addMouseListener(new MouseAdapter() {
                    @Override
                    public void mouseClicked(MouseEvent e) {
                        showTimeSelectionDialog(movie);
                    }
                });
            }

            // Заглавие
            // Намаляваме ширината за пренасяне (например с 30 пиксела по-малко от постера)
            int textWidth = POSTER_WIDTH - 40;
            String htmlTitle = "<html><div style='width: " + textWidth + "px; text-align: center;'>"
                    + movie.title + "</div></html>";

            JLabel titleLabel = new JLabel(htmlTitle);
            titleLabel.setFont(new Font("Arial", Font.BOLD, 18));
            titleLabel.setForeground(TEXT_COLOR);
            titleLabel.setAlignmentX(Component.CENTER_ALIGNMENT);

            // Даваме малко повече височина (55 вместо 50), за да сме сигурни,
            // че двата реда ще се съберат перфектно без да се режат отдолу
            titleLabel.setPreferredSize(new Dimension(POSTER_WIDTH, 55));
            titleLabel.setMaximumSize(new Dimension(POSTER_WIDTH, 55));

            // Дата на излизане
            JLabel dateLabel = new JLabel(movie.premiereDate);
            dateLabel.setFont(new Font("Arial", Font.BOLD, 14));
            dateLabel.setForeground(TEXT_COLOR);
            dateLabel.setAlignmentX(Component.CENTER_ALIGNMENT);

            card.add(posterPanel);
            card.add(Box.createVerticalStrut(15));
            card.add(titleLabel);
            card.add(Box.createVerticalStrut(5));
            card.add(dateLabel);

            gridPanel.add(card);
        }

        mainPanel.add(gridPanel, BorderLayout.CENTER);
        return mainPanel;
    }

    // Раздел "Цени"
    private JPanel createPricesPanel() {
        JPanel panel = new JPanel(new GridBagLayout()); // За центриране на съдържанието
        panel.setBackground(BG_COLOR);

        String pricesText = "Standart: 10€\n" +
                "Student: 8€\n" +
                "Kids under 13: 6.50€";

        JTextArea textArea = new JTextArea(pricesText);
        textArea.setFont(new Font("Arial", Font.BOLD, 26));
        textArea.setForeground(TEXT_COLOR);
        textArea.setBackground(BG_COLOR);
        textArea.setEditable(false);
        textArea.setOpaque(false);
        textArea.setFocusable(false);

        panel.add(textArea);
        return panel;
    }

    // Pop-up за избор на час
    private void showTimeSelectionDialog(Movie movie) {
        JDialog dialog = new JDialog(this, "Time Selection", true);
        dialog.setSize(400, 220);
        dialog.setLocationRelativeTo(this);
        dialog.getContentPane().setBackground(BG_COLOR);
        dialog.setLayout(new BorderLayout());

        JLabel label = new JLabel("Choose screening time: " + movie.title, SwingConstants.CENTER);
        label.setFont(new Font("Arial", Font.BOLD, 16));
        label.setForeground(TEXT_COLOR);
        label.setBorder(new EmptyBorder(15, 0, 10, 0));
        dialog.add(label, BorderLayout.NORTH);

        JPanel buttonsPanel = new JPanel(new FlowLayout());
        buttonsPanel.setBackground(BG_COLOR);

        for (String time : movie.showTimes) {
            JButton timeButton = new JButton(time);
            timeButton.setFont(new Font("Arial", Font.BOLD, 16));
            timeButton.setBackground(ACCENT_COLOR);
            timeButton.setForeground(BG_COLOR);
            timeButton.setFocusPainted(false);

            timeButton.addActionListener(e -> {
                dialog.dispose();
                showSeatSelectionDialog(movie, time);
            });

            buttonsPanel.add(timeButton);
        }

        dialog.add(buttonsPanel, BorderLayout.CENTER);
        dialog.setVisible(true);
    }

    // Pop-up със схема на залата
    private void showSeatSelectionDialog(Movie movie, String selectedTime) {
        JDialog dialog = new JDialog(this, "Seats Selection", true);
        dialog.setSize(650, 550);
        dialog.setLocationRelativeTo(this);
        dialog.getContentPane().setBackground(BG_COLOR);
        dialog.setLayout(new BorderLayout());

        JLabel infoLabel = new JLabel("Movie: " + movie.title + " | Time: " + selectedTime, SwingConstants.CENTER);
        infoLabel.setFont(new Font("Arial", Font.BOLD, 18));
        infoLabel.setForeground(TEXT_COLOR);
        infoLabel.setBorder(new EmptyBorder(15, 10, 10, 10));
        dialog.add(infoLabel, BorderLayout.NORTH);

        JPanel centerPanel = new JPanel(new BorderLayout());
        centerPanel.setBackground(BG_COLOR);
        centerPanel.setBorder(new EmptyBorder(10, 30, 10, 30));

        JLabel screenLabel = new JLabel("SCREEN", SwingConstants.CENTER);
        screenLabel.setOpaque(true);
        screenLabel.setBackground(Color.DARK_GRAY);
        screenLabel.setForeground(Color.WHITE);
        screenLabel.setFont(new Font("Arial", Font.BOLD, 16));
        screenLabel.setBorder(new EmptyBorder(8, 8, 8, 8));

        centerPanel.add(screenLabel, BorderLayout.NORTH);

        JPanel seatsPanel = new JPanel(new GridLayout(5, 8, 8, 8));
        seatsPanel.setBackground(BG_COLOR);
        seatsPanel.setBorder(new EmptyBorder(25, 0, 10, 0));

        List<JButton> selectedSeats = new ArrayList<>();

        for (int row = 1; row <= 5; row++) {
            for (int seat = 1; seat <= 8; seat++) {
                JButton seatButton = new JButton(row + "-" + seat);
                seatButton.setFocusPainted(false);

                // Генерираме 30% шанс мястото да е вече заето
                boolean isTaken = Math.random() < 0.3;

                if (isTaken) {
                    // Стилизиране на заетото място
                    seatButton.setBackground(TAKEN_SEAT_COLOR);
                    seatButton.setForeground(Color.GRAY);
                    // Умишлено не слагаме Hand Cursor и ActionListener,
                    // за да бъде неактивно (потребителят не може да цъка на него)
                } else {
                    // Стилизиране на свободното място
                    seatButton.setBackground(FREE_SEAT_COLOR);
                    seatButton.setForeground(TEXT_COLOR);
                    seatButton.setCursor(new Cursor(Cursor.HAND_CURSOR));

                    // Добавяме логика за кликване САМО на свободните места
                    seatButton.addActionListener(e -> {
                        if (selectedSeats.contains(seatButton)) {
                            selectedSeats.remove(seatButton);
                            seatButton.setBackground(FREE_SEAT_COLOR);
                            seatButton.setForeground(TEXT_COLOR);
                        } else {
                            selectedSeats.add(seatButton);
                            seatButton.setBackground(SELECTED_SEAT_COLOR);
                            seatButton.setForeground(BG_COLOR);
                        }
                    });
                }

                seatsPanel.add(seatButton);
            }
        }

        centerPanel.add(seatsPanel, BorderLayout.CENTER);
        dialog.add(centerPanel, BorderLayout.CENTER);

        JButton confirmButton = new JButton("Confirm");
        confirmButton.setFont(new Font("Arial", Font.BOLD, 16));
        confirmButton.setBackground(ACCENT_COLOR);
        confirmButton.setForeground(BG_COLOR);
        confirmButton.setFocusPainted(false);

        confirmButton.addActionListener(e -> {
            if (selectedSeats.isEmpty()) {
                JOptionPane.showMessageDialog(dialog, "Please select at least one seat.", "No seats selected", JOptionPane.WARNING_MESSAGE);
                return;
            }
            JOptionPane.showMessageDialog(dialog, "Successfully selected " + selectedSeats.size() + " seats!", "Reservation", JOptionPane.INFORMATION_MESSAGE);
            dialog.dispose();
            switchTab("ON_SCREEN", onScreenBtn);
        });

        JPanel bottomPanel = new JPanel();
        bottomPanel.setBackground(BG_COLOR);
        bottomPanel.setBorder(new EmptyBorder(10, 10, 20, 10));
        bottomPanel.add(confirmButton);

        dialog.add(bottomPanel, BorderLayout.SOUTH);
        dialog.setVisible(true);
    }

    private ImageIcon loadPosterIcon(String fileName, String movieTitle, int width, int height) {
        File imageFile = Paths.get("images", fileName).toFile();
        if (imageFile.exists()) {
            ImageIcon originalIcon = new ImageIcon(imageFile.getAbsolutePath());
            Image scaledImage = originalIcon.getImage().getScaledInstance(width, height, Image.SCALE_SMOOTH);
            return new ImageIcon(scaledImage);
        }
        return createFallbackPoster(width, height);
    }

    // Тъмен placeholder, наподобяващ дизайна
    private ImageIcon createFallbackPoster(int width, int height) {
        BufferedImage image = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
        Graphics2D g = image.createGraphics();
        g.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

        g.setColor(BG_COLOR);
        g.fillRect(0, 0, width, height);

        g.setColor(TEXT_COLOR);
        g.setFont(new Font("Arial", Font.BOLD, 22));
        FontMetrics metrics = g.getFontMetrics();
        String text = "poster";
        int x = (width - metrics.stringWidth(text)) / 2;
        int y = (height - metrics.getHeight()) / 2 + metrics.getAscent();

        g.drawString(text, x, y);
        g.dispose();
        return new ImageIcon(image);
    }

    // Метод за четене от CSV без външни библиотеки
    // Метод за четене от CSV без външни библиотеки (с разделител запетая)
    private void loadMoviesFromCSV(String filePath, List<Movie> onScreen, List<Movie> soon) {
        File file = new File(filePath);
        if (!file.exists()) {
            System.err.println("CSV file not found at: " + file.getAbsolutePath());
            return;
        }

        try (BufferedReader br = new BufferedReader(new FileReader(file))) {
            String line;
            boolean isFirstRow = true;

            while ((line = br.readLine()) != null) {
                if (isFirstRow) {
                    isFirstRow = false;
                    continue;
                }

                // Магията на Regex: Разделя по запетая, НО игнорира запетаите, които са вътре в двойни кавички
                String[] data = line.split(",(?=(?:[^\"]*\"[^\"]*\")*[^\"]*$)", -1);

                if (data.length < 5) continue;

                // Взимаме данните и премахваме кавичките, ако Excel ги е сложил, след което махаме празните интервали
                String title = data[0].replaceAll("^\"|\"$", "").trim();
                String poster = data[1].replaceAll("^\"|\"$", "").trim();
                String timesStr = data[2].replaceAll("^\"|\"$", "").trim();
                String premiere = data[3].replaceAll("^\"|\"$", "").trim();
                String category = data[4].replaceAll("^\"|\"$", "").trim();

                if (title.isEmpty()) continue;

                // Разделяме часовете по запетая (вътре в самата клетка)
                String[] times = timesStr.isEmpty() ? new String[0] : timesStr.split(",\\s*");

                Movie movie = new Movie(title, poster, times, premiere);

                if ("SOON".equalsIgnoreCase(category)) {
                    soon.add(movie);
                } else {
                    onScreen.add(movie);
                }
            }
            System.out.println("Successfully loaded movies from CSV!");

        } catch (IOException e) { // Вече използваме специфичния IOException
            System.err.println("Error reading CSV file!");
            e.printStackTrace();
        }
    }
    // --- ПЕРСОНАЛИЗИРАНИ КОМПОНЕНТИ ---

    // Бутон за навигация тип "хапче"
    class NavButton extends JButton {
        private boolean active;

        public NavButton(String text, boolean active) {
            super(text);
            this.active = active;
            setFont(new Font("Arial", Font.BOLD, 18));
            setForeground(TEXT_COLOR);
            setContentAreaFilled(false);
            setFocusPainted(false);
            setBorderPainted(false);
            setCursor(new Cursor(Cursor.HAND_CURSOR));
            setPreferredSize(new Dimension(150, 45));
        }

        public void setActive(boolean active) {
            this.active = active;
            repaint();
        }

        @Override
        protected void paintComponent(Graphics g) {
            Graphics2D g2 = (Graphics2D) g.create();
            g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

            if (active) {
                g2.setColor(ACCENT_COLOR);
                g2.fillRoundRect(0, 0, getWidth(), getHeight(), 40, 40);
            } else {
                g2.setColor(BG_COLOR);
                g2.fillRoundRect(0, 0, getWidth(), getHeight(), 40, 40);
                g2.setColor(ACCENT_COLOR);
                g2.setStroke(new BasicStroke(2f));
                g2.drawRoundRect(1, 1, getWidth() - 3, getHeight() - 3, 40, 40);
            }

            // Рисуване на текста центрирано
            FontMetrics fm = g2.getFontMetrics();
            int stringWidth = fm.stringWidth(getText());
            int stringAscent = fm.getAscent();
            int x = getWidth() / 2 - stringWidth / 2;
            int y = getHeight() / 2 + stringAscent / 2 - 2;

            g2.setColor(TEXT_COLOR);
            g2.drawString(getText(), x, y);

            g2.dispose();
        }
    }

    // Панел за постера със заоблена оранжева рамка
    class RoundedPosterPanel extends JPanel {
        private final ImageIcon icon;

        public RoundedPosterPanel(ImageIcon icon) {
            this.icon = icon;
            setPreferredSize(new Dimension(POSTER_WIDTH, POSTER_HEIGHT));
            setMaximumSize(new Dimension(POSTER_WIDTH, POSTER_HEIGHT));
            setOpaque(false);
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            Graphics2D g2 = (Graphics2D) g.create();
            // Включваме anti-aliasing за гладки ръбове
            g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

            // Дефинираме формата на заобления правоъгълник
            int arc = 25; // Радиус на заоблянето
            java.awt.geom.RoundRectangle2D roundedRectangle = new java.awt.geom.RoundRectangle2D.Float(
                    1, 1, getWidth() - 3, getHeight() - 3, arc, arc);

            // Ограничаваме (clip) рисуването само в рамките на заоблената форма
            g2.setClip(roundedRectangle);

            // Рисуваме самото изображение - то автоматично ще се изреже по заоблените ъгли
            if (icon != null) {
                g2.drawImage(icon.getImage(), 0, 0, getWidth(), getHeight(), this);
            }

            // Премахваме ограничението, за да можем да нарисуваме рамката гладко отгоре
            g2.setClip(null);

            // Рисуване на оранжевата рамка
            g2.setColor(ACCENT_COLOR);
            g2.setStroke(new BasicStroke(3f));
            g2.draw(roundedRectangle);

            g2.dispose();
        }
    }

    // Клас за филм
    private static class Movie {
        String title;
        String posterFileName;
        String[] showTimes;
        String premiereDate;

        Movie(String title, String posterFileName, String[] showTimes, String premiereDate) {
            this.title = title;
            this.posterFileName = posterFileName;
            this.showTimes = showTimes;
            this.premiereDate = premiereDate;
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            CinemaApp app = new CinemaApp();
            app.setVisible(true);
        });
    }
}