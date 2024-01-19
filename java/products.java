package cps2004.java;

public class products {
    protected String name;
    protected double price;
    protected String supplier;
    protected int packagingUnits;

    // Constructors
    public products() {
    }

    public products(String name, double price, String supplier, int packagingUnits) {
        this.name = name;
        this.price = price;
        this.supplier = supplier;
        this.packagingUnits = packagingUnits;
    }

    // Getters
    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }

    public String getSupplier() {
        return supplier;
    }

    public int getPackagingUnits() {
        return packagingUnits;
    }

    // Setters
    public void setName(String name) {
        this.name = name;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public void setSupplier(String supplier) {
        this.supplier = supplier;
    }

    public void setPackagingUnits(int units) {
        this.packagingUnits = units;
    }

    // Methods
    public void displayInfo() {
        System.out.println("\nName: " + name + ", Price: " + price + ", Supplier: " + supplier + ", Units: " + packagingUnits);
    }

    public double calculateDiscount(int quantity, int month) {
        return quantity * month;
    }

    public boolean equals(products product) {
        return this.name.equals(product.getName()) &&
                Double.compare(this.price, product.getPrice()) == 0 &&
                this.supplier.equals(product.getSupplier());
    }
}

