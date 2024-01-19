package cps2004.java;

public class jewelry extends products {
    private String material;
    private String gemstone;
    private String design;

    // Constructors
    public jewelry(String n, double a, String m, int x, String material, String gemstone, String design) {
        super(n, a, m, x);
        this.material = material;
        this.gemstone = gemstone;
        this.design = design;
    }

    // Getters
    public String getMaterial() {
        return material;
    }

    public String getGemstone() {
        return gemstone;
    }

    public String getDesign() {
        return design;
    }

    // Setters
    public void setMaterial(String material) {
        this.material = material;
    }

    public void setGemstone(String gemstone) {
        this.gemstone = gemstone;
    }

    public void setDesign(String design) {
        this.design = design;
    }

    // Methods
    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println(", Material: " + material + ", Gemstone: " + gemstone + ", Design: " + design);
    }

    public void displayJewelryInfo() {
        System.out.println(", Material: " + material + ", Gemstone: " + gemstone + ", Design: " + design);
    }

    public double calculateDiscount(int quantity, int month) {
        if (quantity > 2) {
            return quantity * month * 0.15;
        } else {
            return quantity * month;
        }
    }
}
