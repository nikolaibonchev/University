public class Movie {
    public String title;
    public String posterFileName;
    public String[] showTimes;
    public String premiereDate;

    public Movie(String title, String posterFileName, String[] showTimes, String premiereDate) {
        this.title = title;
        this.posterFileName = posterFileName;
        this.showTimes = showTimes;
        this.premiereDate = premiereDate;
    }
}