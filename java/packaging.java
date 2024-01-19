package cps2004.java;

import java.util.List;
import java.util.Random;

public class packaging {

    private String packing;
    private String id;
    private double cost;
    private int capacity;

    // Constructors
    public packaging() {
    }

    public packaging(String packing, double cost, int capacity) {
        this.packing = packing;
        this.id = generateUniqueID();
        this.cost = cost;
        this.capacity = capacity;
    }

    // Getters
    public String getPacking() {
        return packing;
    }

    public String getId() {
        return id;
    }

    public double getCost() {
        return cost;
    }

    public int getCapacity() {
        return capacity;
    }

    // Setters
    public void setPacking(String packaging) {
        this.packing = packaging;
    }

    public void setId(String id) {
        this.id = id;
    }

    public void setCost(double cost) {
        this.cost = cost;
    }

    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    // Methods
    public String generateUniqueID() {
        final String characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        StringBuilder id = new StringBuilder();
        Random random = new Random();
        for (int i = 0; i < 10; ++i) {
            char x = characters.charAt(random.nextInt(characters.length()));
            id.append(x);
        }
        return id.toString();
    }

    public void addPackaging(packaging packagings, List<packaging> array) {
        array.add(packagings);
    }

    public void deletePackaging(List<packaging> array, int pos) {
        array.remove(pos);
    }
}

