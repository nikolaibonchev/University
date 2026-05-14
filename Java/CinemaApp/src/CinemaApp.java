import javax.swing.*;
import java.awt.*;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class CinemaApp extends JFrame {

    public static final Color BG_COLOR = Color.BLACK;
    public static final Color TEXT_COLOR = Color.WHITE;
    public static final Color ACCENT_COLOR = new Color(127, 0, 255);
    public static final Color FREE_SEAT_COLOR = new Color(50, 50, 50);
    public static final Color SELECTED_SEAT_COLOR = ACCENT_COLOR;
    public static final Color TAKEN_SEAT_COLOR = new Color(80, 25, 25);
    public static final int POSTER_WIDTH = 180;
    public static final int POSTER_HEIGHT = 260;

    private JPanel cardPanel;
    private CardLayout cardLayout;
    private UIComponents.NavButton onScreenBtn, soonBtn, pricesBtn;

    public CinemaApp() {
        setTitle("CinemaBests");
        setSize(950, 700);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setExtendedState(JFrame.MAXIMIZED_BOTH);
        getContentPane().setBackground(BG_COLOR);
        setLayout(new BorderLayout());

        List<Movie> nowMovies = new ArrayList<>();
        List<Movie> comingSoonMovies = new ArrayList<>();

        loadMoviesFromCSV("movies.csv", nowMovies, comingSoonMovies);

        add(createNavBar(), BorderLayout.NORTH);

        cardLayout = new CardLayout();
        cardPanel = new JPanel(cardLayout);
        cardPanel.setBackground(BG_COLOR);
        cardPanel.add(UIPanels.createMovieGridPanel(this, nowMovies, true), "ON_SCREEN");
        cardPanel.add(UIPanels.createMovieGridPanel(this, comingSoonMovies, false), "SOON");
        cardPanel.add(UIPanels.createPricesPanel(), "PRICES");

        add(cardPanel, BorderLayout.CENTER);
    }

    private JPanel createNavBar() {
        JPanel navPanel = new JPanel(new FlowLayout(FlowLayout.CENTER, 20, 20));
        navPanel.setBackground(BG_COLOR);
        onScreenBtn = new UIComponents.NavButton("ON SCREEN", true);
        soonBtn = new UIComponents.NavButton("SOON", false);
        pricesBtn = new UIComponents.NavButton("PRICES", false);

        onScreenBtn.addActionListener(e -> switchTab("ON_SCREEN", onScreenBtn));
        soonBtn.addActionListener(e -> switchTab("SOON", soonBtn));
        pricesBtn.addActionListener(e -> switchTab("PRICES", pricesBtn));

        navPanel.add(onScreenBtn);
        navPanel.add(soonBtn);
        navPanel.add(pricesBtn);

        return navPanel;
    }

    private void switchTab(String cardName, UIComponents.NavButton activeBtn) {
        cardLayout.show(cardPanel, cardName);
        onScreenBtn.setActive(false);
        soonBtn.setActive(false);
        pricesBtn.setActive(false);
        activeBtn.setActive(true);
    }
    public void returnToOnScreen() {
        switchTab("ON_SCREEN", onScreenBtn);
    }

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

                String[] data = line.split(",(?=(?:[^\"]*\"[^\"]*\")*[^\"]*$)", -1);

                if (data.length < 5) continue;

                String title = data[0].replaceAll("^\"|\"$", "").trim();
                String poster = data[1].replaceAll("^\"|\"$", "").trim();
                String timesStr = data[2].replaceAll("^\"|\"$", "").trim();
                String premiere = data[3].replaceAll("^\"|\"$", "").trim();
                String category = data[4].replaceAll("^\"|\"$", "").trim();

                if (title.isEmpty()) continue;

                String[] times = timesStr.isEmpty() ? new String[0] : timesStr.split(",\\s*");

                Movie movie = new Movie(title, poster, times, premiere);

                if ("SOON".equalsIgnoreCase(category)) {
                    soon.add(movie);
                } else {
                    onScreen.add(movie);
                }
            }
            System.out.println("Successfully loaded movies from CSV!");

        } catch (IOException e) {
            System.err.println("Error reading CSV file!");
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            CinemaApp app = new CinemaApp();
            app.setVisible(true);
        });
    }
}