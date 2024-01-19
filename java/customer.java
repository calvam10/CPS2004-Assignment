package cps2004.java;

import java.util.Random;

public class customer {

    private String name;
    private int age;
    private String id;
    private int distance;

    // Constructors
    public customer() {

    }

    public customer(String name, int age, int distance) {
        this.name = name;
        this.age = age;
        this.id = generateUniqueID();
        this.distance = distance;
    }

    // Getters
    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public String getId() {
        return id;
    }

    public int getDistance() {
        return distance;
    }

    // Setters
    public void setName(String name) {
        this.name = name;
    }

    public void setId(String id) {
        this.id = id;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void setDistance(int distance) {
        this.distance = distance;
    }

    // Methods
    private String generateUniqueID() {
        String characters = "0123456789";
        StringBuilder id = new StringBuilder();
        Random random = new Random();
        for (int i = 0; i < 8; ++i) {
            char x = characters.charAt(random.nextInt(characters.length()));
            id.append(x);
        }
        return id.toString();
    }

    public void displayInfo() {
            System.out.println("Name: " + this.getName() + ", Age: " + this.getAge() + ", Id: " + this.getId());
    }
}
