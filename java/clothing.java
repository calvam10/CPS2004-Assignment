package cps2004.java;

public class clothing extends products {
    private String brand;
    private char size;
    private String color;

    // Constructors
    public clothing(String n, double a, String m, int x, String brand, char size, String color) {
        super(n, a, m, x);
        this.brand = brand;
        this.size = size;
        this.color = color;
    }

    // Getters
    public String getBrand() {
        return brand;
    }

    public char getSize() {
        return size;
    }

    public String getColor() {
        return color;
    }

    // Setters
    public void setBrand(String brand) {
        this.brand = brand;
    }

    public void setSize(char size) {
        this.size = size;
    }

    public void setColor(String color) {
        this.color = color;
    }

    // Methods
    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println(", Brand: " + brand + ", Size: " + size + ", Color: " + color);
    }

    public void displayClothingInfo() {
        System.out.println(", Brand: " + brand + ", Size: " + size + ", Color: " + color);
    }

    public double calculateDiscount(int quantity, int month) {
        if (quantity > 15) {
            return quantity * month * 0.3;
        } else {
            return quantity * month * 0.5;
        }
    }
}
