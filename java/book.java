package cps2004.java;

public class book extends products {
    private String author;
    private String genre;
    private int yearOfPublication;

    // Constructors
    public book(String n, double a, String m, int x, String author, String genre, int year) {
        super(n, a, m, x);
        this.author = author;
        this.genre = genre;
        this.yearOfPublication = year;
    }

    // Getters
    public String getAuthor() {
        return author;
    }

    public String getGenre() {
        return genre;
    }

    public int getYearOfPublication() {
        return yearOfPublication;
    }

    // Setters
    public void setAuthor(String author) {
        this.author = author;
    }

    public void setGenre(String genre) {
        this.genre = genre;
    }

    public void setYearOfPublication(int year) {
        this.yearOfPublication = year;
    }

    // Methods
    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Author: " + author + ", Genre: " + genre + ", Year of Publication: " + yearOfPublication);
    }

    public void displayBookInfo() {
        System.out.println("Author: " + author + ", Genre: " + genre + ", Year of Publication: " + yearOfPublication);
    }

    public double calculateDiscount(int quantity, int month) {
        if (quantity > 10) {
            return quantity * month * 0.6;
        } else {
            return quantity * month * 0.8;
        }
    }
}