package cps2004.java;

public class truck extends transport {
    private String route;

    // Constructors
    public truck(String m, double n, double a, String x) {
        super(m, n, a);
        this.route = x;
    }

    // Getter
    public String getRoute() {
        return route;
    }

    // Methods
    @Override
    public void displayInfo(transport transport) {
        super.displayInfo(transport);
        System.out.println(", Route: " + route);
    }

    public void displayTruckInfo() {
        System.out.println("Route: " + route);
    }
}

