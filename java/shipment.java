package cps2004.java;

import java.util.List;
import java.util.Date;
import java.text.SimpleDateFormat;

public class shipment {

    private customer cust;
    private transport transport;
    private List<products> productsPackaged;
    private Date dispatchDate;
    private Date deliveryDate;
    private String status;
    private double totalUnits;
    private double totalCost;

    // Constructors
    public shipment() {}

    public shipment(customer cust, transport transport, List<products> productsPackaged) {
        this.cust = cust;
        this.transport = transport;
        this.productsPackaged = productsPackaged;
        this.dispatchDate = new Date(System.currentTimeMillis() + (24 * 2 * 60 * 60 * 1000)); // 2 days
        this.deliveryDate = new Date(System.currentTimeMillis() + (24 * 2 * 60 * 60 * 1000) +((int)calculateDeliveryTime()*60 * 60 * 1000));
        this.status = "Dispatching";
    }

    // Getters & Setters
    public customer getCustomer() {
        return cust;
    }

    public transport getTransport() {
        return transport;
    }

    public List<products> getProductsPackaged(){
        return productsPackaged;
    }

    public double getTotalUnits(){
        return totalUnits;
    }
    
    public double getTotalPrice() {
        return totalCost;
    }
    public void setCustomer(customer cust) {
        this.cust = cust;
    }

    public void setTransport(transport transport) {
        this.transport = transport;
    }

    public void setTotalUnits(double units){
        this.totalUnits = units;
    }

    public void setStatus(String status){
        this.status = status;
    }

    public void setTotalPrice(double total){
        this.totalCost = total;
    }

    // Other Methods
    public void addShipment(shipment shipment, List<shipment> array) {
        array.add(shipment);
    }

    public void deleteShipment(List<shipment> array, int pos) {
        array.remove(pos);
    }

    public void displayInfo() {
        System.out.println("Customer: " + cust.getName() + ", Transport: " + transport.getName());
        System.out.println("List of Products: ");
        for (products product : this.productsPackaged) {
            product.displayInfo();
            System.out.println();
        }
        System.out.println("Total price of the products: " + calculateProductsPrice());
        System.out.println("Total price of the transport: " + calculateTransportCost());
        System.out.println("Total price of the packagings: " + getTotalUnits());

        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        System.out.println("Expected Date of Dispatch: " + sdf.format(dispatchDate) +
                " - Expected Time of Delivery: " + sdf.format(deliveryDate));

        System.out.println("\nStatus: " + status);
    }

    public void addProduct(products product) {
        boolean added = false;
        if (this.productsPackaged.isEmpty()) {
            this.productsPackaged.add(product);
            added = true;
        } else {
            for (int i = 0; i < this.productsPackaged.size(); i++) {
                if (this.productsPackaged.get(i).equals(product)) {
                    this.productsPackaged.get(i).setPackagingUnits(
                            this.productsPackaged.get(i).getPackagingUnits() + product.getPackagingUnits());
                    added = true;
                    break;
                }
            }
            if (!added) {
                this.productsPackaged.add(product);
            }
        }
    }

    public boolean isDispatched() {
        return System.currentTimeMillis() > this.dispatchDate.getTime();
    }

    public void cancel() {
        // Implementation for cancellation
    }

    public double calculateProductsPrice() {
        double total = 0;
        for (products product : this.productsPackaged) {
            total += product.getPrice() * product.getPackagingUnits();
        }
        return total;
    }

    public double calculateDeliveryTime() {
        return this.cust.getDistance() / this.transport.getSpeed();
    }

    public double calculateTransportCost() {
        return this.cust.getDistance() * this.transport.getCost();
    }

    public void updateShipments(List<products> auxList, customer customer, transport transport,double total) {
        for(int i=0;i<auxList.size();i++){
            this.addProduct(auxList.get(i));
        }
        this.setCustomer(customer);
        this.setTransport(transport);
        this.setTotalPrice(total);
    }

}
