package cps2004.java;

public class computergames extends products {
    private String company;
    private String console;
    private int minimumAge;

    // Constructors
    public computergames(String n, double a, String m, int x, String company, String console, int age) {
        super(n, a, m, x);
        this.company = company;
        this.console = console;
        this.minimumAge = age;
    }

    // Getters
    public String getCompany() {
        return company;
    }

    public String getConsole() {
        return console;
    }

    public int getMinimumAge() {
        return minimumAge;
    }

    // Setters
    public void setCompany(String company) {
        this.company = company;
    }

    public void setConsole(String console) {
        this.console = console;
    }

    public void setMinimumAge(int age) {
        this.minimumAge = age;
    }

    // Methods
    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println(", Company: " + company + ", Console: " + console + ", Minimum Age: " + minimumAge);
    }

    public void displayComputerGamesInfo() {
        System.out.println(", Company: " + company + ", Console: " + console + ", Minimum Age: " + minimumAge);
    }

    public double calculateDiscount(int quantity, int month) {
        if (quantity > 3) {
            return quantity * month * 0.15;
        } else {
            return quantity * month * 0.90;
        }
    }
}

