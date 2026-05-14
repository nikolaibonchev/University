import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.List;

public class UIPanels {

    public static JPanel createMovieGridPanel(CinemaApp app, List<Movie> movies, boolean isOnScreen) {
        JPanel mainPanel = new JPanel(new BorderLayout());
        mainPanel.setBackground(CinemaApp.BG_COLOR);
        mainPanel.setBorder(new EmptyBorder(40, 40, 40, 40));

        JPanel gridPanel = new JPanel(new FlowLayout(FlowLayout.CENTER, 30, 20));
        gridPanel.setBackground(CinemaApp.BG_COLOR);

        for (Movie movie : movies) {
            JPanel card = new JPanel();
            card.setLayout(new BoxLayout(card, BoxLayout.Y_AXIS));
            card.setBackground(CinemaApp.BG_COLOR);

            UIComponents.RoundedPosterPanel posterPanel = new UIComponents.RoundedPosterPanel(
                    UIComponents.loadPosterIcon(movie.posterFileName, movie.title, CinemaApp.POSTER_WIDTH, CinemaApp.POSTER_HEIGHT)
            );
            posterPanel.setAlignmentX(Component.CENTER_ALIGNMENT);
            posterPanel.setCursor(new Cursor(Cursor.HAND_CURSOR));

            if (isOnScreen) {
                posterPanel.addMouseListener(new MouseAdapter() {
                    @Override
                    public void mouseClicked(MouseEvent e) {
                        UIDialogs.showTimeSelectionDialog(app, movie);
                    }
                });
            }

            int textWidth = CinemaApp.POSTER_WIDTH - 40;
            String htmlTitle = "<html><div style='width: " + textWidth + "px; text-align: center;'>"
                    + movie.title + "</div></html>";

            JLabel titleLabel = new JLabel(htmlTitle);
            titleLabel.setFont(new Font("Arial", Font.BOLD, 18));
            titleLabel.setForeground(CinemaApp.TEXT_COLOR);
            titleLabel.setAlignmentX(Component.CENTER_ALIGNMENT);
            titleLabel.setPreferredSize(new Dimension(CinemaApp.POSTER_WIDTH, 55));
            titleLabel.setMaximumSize(new Dimension(CinemaApp.POSTER_WIDTH, 55));

            JLabel dateLabel = new JLabel(movie.premiereDate);
            dateLabel.setFont(new Font("Arial", Font.BOLD, 14));
            dateLabel.setForeground(CinemaApp.TEXT_COLOR);
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

    public static JPanel createPricesPanel() {
        JPanel panel = new JPanel(new GridBagLayout());
        panel.setBackground(CinemaApp.BG_COLOR);

        String pricesText = "Standart: 10€\n" +
                "Student: 8€\n" +
                "Kids under 13: 6.50€";

        JTextArea textArea = new JTextArea(pricesText);
        textArea.setFont(new Font("Arial", Font.BOLD, 26));
        textArea.setForeground(CinemaApp.TEXT_COLOR);
        textArea.setBackground(CinemaApp.BG_COLOR);
        textArea.setEditable(false);
        textArea.setOpaque(false);
        textArea.setFocusable(false);

        panel.add(textArea);
        return panel;
    }
}