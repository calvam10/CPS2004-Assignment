package cps2004.java;

public class furniture extends products {
    private String material;
    private String dimensions;
    private String style;

    // Constructors
    public furniture(String n, double a, String m, int x, String material, String dimensions, String style) {
        super(n, a, m, x);
        this.material = material;
        this.dimensions = dimensions;
        this.style = style;
    }

    // Getters
    public String getMaterial() {
        return material;
    }

    public String getDimensions() {
        return dimensions;
    }

    public String getStyle() {
        return style;
    }

    // Setters
    public void setMaterial(String material) {
        this.material = material;
    }

    public void setDimensions(String dimensions) {
        this.dimensions = dimensions;
    }

    public void setStyle(String style) {
        this.style = style;
    }

    // Methods
    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println(", Material: " + material + ", Dimensions: " + dimensions + ", Style: " + style);
    }

    public void displayFurnitureInfo() {
        System.out.println(", Material: " + material + ", Dimensions: " + dimensions + ", Style: " + style);
    }

    public double calculateDiscount(int quantity, int month) {
        if (quantity > 6) {
            return quantity * month * 0.08;
        } else {
            return quantity * month * 0.62;
        }
    }
}


