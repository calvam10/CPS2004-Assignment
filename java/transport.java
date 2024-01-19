package cps2004.java;

import java.util.List;

public class transport {
    protected String name;
    protected double speed;
    protected double cost;

    // Constructors
    public transport() {
    }

    public transport(String name, double speed, double cost) {
        this.name = name;
        this.speed = speed;
        this.cost = cost;
    }

    // Getters
    public String getName() {
        return name;
    }

    public double getSpeed() {
        return speed;
    }

    public double getCost() {
        return cost;
    }

    // Setters
    public void setName(String name) {
        this.name = name;
    }

    public void setSpeed(double speed) {
        this.speed = speed;
    }

    public void setCost(double cost) {
        this.cost = cost;
    }

    // Methods
    public void displayInfo(transport transport) {
        System.out.println("Name: " + transport.getName() + " , Speed: " + transport.getSpeed() + " , Cost: " + transport.getCost() + " , Route: " + transport.getRoute());

    }

    public double deliveryCost(double distance) {
        return distance * this.cost;
    }

    public String getRoute() {
        return "";
    }

    public void addTransport(transport transport, List<transport> array) {
        array.add(transport);
    }

    public void deleteTransport(List<transport> array, int pos) {
        array.remove(pos);
    }
}