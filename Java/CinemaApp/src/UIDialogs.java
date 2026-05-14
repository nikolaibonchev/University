import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.util.ArrayList;
import java.util.List;

public class UIDialogs {

    public static void showTimeSelectionDialog(CinemaApp app, Movie movie) {
        JDialog dialog = new JDialog(app, "Time Selection", true);
        dialog.setSize(400, 220);
        dialog.setLocationRelativeTo(app);
        dialog.getContentPane().setBackground(CinemaApp.BG_COLOR);
        dialog.setLayout(new BorderLayout());

        JLabel label = new JLabel("Choose screening time: " + movie.title, SwingConstants.CENTER);
        label.setFont(new Font("Arial", Font.BOLD, 16));
        label.setForeground(CinemaApp.TEXT_COLOR);
        label.setBorder(new EmptyBorder(15, 0, 10, 0));
        dialog.add(label, BorderLayout.NORTH);

        JPanel buttonsPanel = new JPanel(new FlowLayout());
        buttonsPanel.setBackground(CinemaApp.BG_COLOR);

        for (String time : movie.showTimes) {
            JButton timeButton = new JButton(time);
            timeButton.setFont(new Font("Arial", Font.BOLD, 16));
            timeButton.setBackground(CinemaApp.ACCENT_COLOR);
            timeButton.setForeground(CinemaApp.BG_COLOR);
            timeButton.setFocusPainted(false);

            timeButton.addActionListener(e -> {
                dialog.dispose();
                showSeatSelectionDialog(app, movie, time);
            });

            buttonsPanel.add(timeButton);
        }

        dialog.add(buttonsPanel, BorderLayout.CENTER);
        dialog.setVisible(true);
    }

    public static void showSeatSelectionDialog(CinemaApp app, Movie movie, String selectedTime) {
        JDialog dialog = new JDialog(app, "Seats Selection", true);
        dialog.setSize(650, 550);
        dialog.setLocationRelativeTo(app);
        dialog.getContentPane().setBackground(CinemaApp.BG_COLOR);
        dialog.setLayout(new BorderLayout());

        JLabel infoLabel = new JLabel("Movie: " + movie.title + " | Time: " + selectedTime, SwingConstants.CENTER);
        infoLabel.setFont(new Font("Arial", Font.BOLD, 18));
        infoLabel.setForeground(CinemaApp.TEXT_COLOR);
        infoLabel.setBorder(new EmptyBorder(15, 10, 10, 10));
        dialog.add(infoLabel, BorderLayout.NORTH);

        JPanel centerPanel = new JPanel(new BorderLayout());
        centerPanel.setBackground(CinemaApp.BG_COLOR);
        centerPanel.setBorder(new EmptyBorder(10, 30, 10, 30));

        JLabel screenLabel = new JLabel("SCREEN", SwingConstants.CENTER);
        screenLabel.setOpaque(true);
        screenLabel.setBackground(Color.DARK_GRAY);
        screenLabel.setForeground(Color.WHITE);
        screenLabel.setFont(new Font("Arial", Font.BOLD, 16));
        screenLabel.setBorder(new EmptyBorder(8, 8, 8, 8));

        centerPanel.add(screenLabel, BorderLayout.NORTH);

        JPanel seatsPanel = new JPanel(new GridLayout(5, 8, 8, 8));
        seatsPanel.setBackground(CinemaApp.BG_COLOR);
        seatsPanel.setBorder(new EmptyBorder(25, 0, 10, 0));

        List<JButton> selectedSeats = new ArrayList<>();

        for (int row = 1; row <= 5; row++) {
            for (int seat = 1; seat <= 8; seat++) {
                JButton seatButton = new JButton(row + "-" + seat);
                seatButton.setFocusPainted(false);

                boolean isTaken = Math.random() < 0.3;

                if (isTaken) {
                    seatButton.setBackground(CinemaApp.TAKEN_SEAT_COLOR);
                    seatButton.setForeground(Color.GRAY);
                } else {
                    seatButton.setBackground(CinemaApp.FREE_SEAT_COLOR);
                    seatButton.setForeground(CinemaApp.TEXT_COLOR);
                    seatButton.setCursor(new Cursor(Cursor.HAND_CURSOR));
                    seatButton.addActionListener(e -> {
                        if (selectedSeats.contains(seatButton)) {
                            selectedSeats.remove(seatButton);
                            seatButton.setBackground(CinemaApp.FREE_SEAT_COLOR);
                            seatButton.setForeground(CinemaApp.TEXT_COLOR);
                        } else {
                            selectedSeats.add(seatButton);
                            seatButton.setBackground(CinemaApp.SELECTED_SEAT_COLOR);
                            seatButton.setForeground(CinemaApp.BG_COLOR);
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
        confirmButton.setBackground(CinemaApp.ACCENT_COLOR);
        confirmButton.setForeground(CinemaApp.BG_COLOR);
        confirmButton.setFocusPainted(false);

        confirmButton.addActionListener(e -> {
            if (selectedSeats.isEmpty()) {
                JOptionPane.showMessageDialog(dialog, "Please select at least one seat.", "No seats selected", JOptionPane.WARNING_MESSAGE);
                return;
            }
            JOptionPane.showMessageDialog(dialog, "Successfully selected " + selectedSeats.size() + " seats!", "Reservation", JOptionPane.INFORMATION_MESSAGE);
            dialog.dispose();

            // Връщаме екрана към първия таб след резервация
            app.returnToOnScreen();
        });

        JPanel bottomPanel = new JPanel();
        bottomPanel.setBackground(CinemaApp.BG_COLOR);
        bottomPanel.setBorder(new EmptyBorder(10, 10, 20, 10));
        bottomPanel.add(confirmButton);

        dialog.add(bottomPanel, BorderLayout.SOUTH);
        dialog.setVisible(true);
    }
}