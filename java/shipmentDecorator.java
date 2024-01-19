package cps2004.java;

abstract class shipmentDecorator extends shipment {
    protected shipment shipment;

    public shipmentDecorator(shipment aux){
        this.shipment = aux;
    }
}

class DiscountDecorator extends shipmentDecorator{
    private double discount;
    
    public DiscountDecorator(shipment shipment, double discount){
        super(shipment);
        this.discount = discount;

    }
    @Override
    public void displayInfo(){
        System.out.println("Global Discount: " + discount + "%");
        System.out.println("===========================");
        shipment.displayInfo();
    }

    public double applyDiscount(shipment test, int discount){
        double originalPrice = test.getTotalPrice();
        double discountedPrice = originalPrice - (originalPrice*discount/100);
        return discountedPrice;
    }
}
