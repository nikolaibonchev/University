import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.nio.file.Paths;

public class UIComponents {

    public static class NavButton extends JButton {
        private boolean active;

        public NavButton(String text, boolean active) {
            super(text);
            this.active = active;
            setFont(new Font("Arial", Font.BOLD, 18));
            setForeground(CinemaApp.TEXT_COLOR);
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
                g2.setColor(CinemaApp.ACCENT_COLOR);
                g2.fillRoundRect(0, 0, getWidth(), getHeight(), 40, 40);
            } else {
                g2.setColor(CinemaApp.BG_COLOR);
                g2.fillRoundRect(0, 0, getWidth(), getHeight(), 40, 40);
                g2.setColor(CinemaApp.ACCENT_COLOR);
                g2.setStroke(new BasicStroke(2f));
                g2.drawRoundRect(1, 1, getWidth() - 3, getHeight() - 3, 40, 40);
            }

            FontMetrics fm = g2.getFontMetrics();
            int stringWidth = fm.stringWidth(getText());
            int stringAscent = fm.getAscent();
            int x = getWidth() / 2 - stringWidth / 2;
            int y = getHeight() / 2 + stringAscent / 2 - 2;

            g2.setColor(CinemaApp.TEXT_COLOR);
            g2.drawString(getText(), x, y);

            g2.dispose();
        }
    }

    public static class RoundedPosterPanel extends JPanel {
        private final ImageIcon icon;

        public RoundedPosterPanel(ImageIcon icon) {
            this.icon = icon;
            setPreferredSize(new Dimension(CinemaApp.POSTER_WIDTH, CinemaApp.POSTER_HEIGHT));
            setMaximumSize(new Dimension(CinemaApp.POSTER_WIDTH, CinemaApp.POSTER_HEIGHT));
            setOpaque(false);
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            Graphics2D g2 = (Graphics2D) g.create();
            g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

            int arc = 25;
            java.awt.geom.RoundRectangle2D roundedRectangle = new java.awt.geom.RoundRectangle2D.Float(
                    1, 1, getWidth() - 3, getHeight() - 3, arc, arc);

            g2.setClip(roundedRectangle);

            if (icon != null) {
                g2.drawImage(icon.getImage(), 0, 0, getWidth(), getHeight(), this);
            }

            g2.setClip(null);
            g2.setColor(CinemaApp.ACCENT_COLOR);
            g2.setStroke(new BasicStroke(3f));
            g2.draw(roundedRectangle);

            g2.dispose();
        }
    }

    public static ImageIcon loadPosterIcon(String fileName, String movieTitle, int width, int height) {
        File imageFile = Paths.get("images", fileName).toFile();
        if (imageFile.exists()) {
            ImageIcon originalIcon = new ImageIcon(imageFile.getAbsolutePath());
            Image scaledImage = originalIcon.getImage().getScaledInstance(width, height, Image.SCALE_SMOOTH);
            return new ImageIcon(scaledImage);
        }
        return createFallbackPoster(width, height);
    }

    private static ImageIcon createFallbackPoster(int width, int height) {
        BufferedImage image = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
        Graphics2D g = image.createGraphics();
        g.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

        g.setColor(CinemaApp.BG_COLOR);
        g.fillRect(0, 0, width, height);

        g.setColor(CinemaApp.TEXT_COLOR);
        g.setFont(new Font("Arial", Font.BOLD, 22));
        FontMetrics metrics = g.getFontMetrics();
        String text = "poster";
        int x = (width - metrics.stringWidth(text)) / 2;
        int y = (height - metrics.getHeight()) / 2 + metrics.getAscent();

        g.drawString(text, x, y);
        g.dispose();
        return new ImageIcon(image);
    }
}