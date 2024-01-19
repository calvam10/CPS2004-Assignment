package cps2004.java;

public class electronics extends products {
    private String brand;
    private String placeOfManufacture;
    private int power;

    // Constructors
    public electronics(String n, double a, String m, int x, String brand, String place, int power) {
        super(n, a, m, x);
        this.brand = brand;
        this.placeOfManufacture = place;
        this.power = power;
    }

    // Getters
    public String getBrand() {
        return brand;
    }

    public String getPlaceOfManufacture() {
        return placeOfManufacture;
    }

    public int getPower() {
        return power;
    }

    // Setters
    public void setBrand(String brand) {
        this.brand = brand;
    }

    public void setPlaceOfManufacture(String place) {
        this.placeOfManufacture = place;
    }

    public void setPower(int power) {
        this.power = power;
    }

    // Methods
    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println(", Brand: " + brand + ", Place of Manufacture: " + placeOfManufacture + ", Power: " + power + "W");
    }

    public void displayElectronicsInfo() {
        System.out.println(", Brand: " + brand + ", Place of Manufacture: " + placeOfManufacture + ", Power: " + power + "W");
    }

    public double calculateDiscount(int quantity, int month) {
        if (quantity > 6) {
            return quantity * month * 0.1;
        } else {
            return quantity * month * 0.75;
        }
    }
}
