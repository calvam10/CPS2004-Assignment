package cps2004.java;

import java.util.List;

public class stock {
    private List<products> list;

    // Constructors
    public stock() {
    }

    public stock(List<products> list) {
        this.list = list;
    }

    // Methods
    public boolean addProduct(products product, List<products> array) {
        boolean added = false;
        if (array.isEmpty()) {
            array.add(product);
            added = true;
        } else {
            for (int i = 0; i < array.size(); i++) {
                if (array.get(i).equals(product)) {
                    array.get(i).setPackagingUnits(array.get(i).getPackagingUnits() + product.getPackagingUnits());
                    added = true;
                    break;
                }
            }
            if (!added) {
                array.add(product);
            }
        }
        return added;
    }

    public boolean deleteProduct(int pos, int quantity, List<products> array) {
        boolean deleted = false;
        if (!array.isEmpty()) {
            for (int i = 0; i < array.size(); i++) {
                if (array.get(i).getName().equals(array.get(pos).getName())) {
                    if (array.get(i).getPackagingUnits() > quantity) {
                        array.get(i).setPackagingUnits(array.get(i).getPackagingUnits() - quantity);
                        System.out.println("Reduce the quantity of the Product selected");
                    } else {
                        array.remove(i);
                        deleted = true;
                    }
                } else {
                    System.out.println("The product is not in the stock");
                }
            }
        }
        return deleted;
    }

    public void displayStock(List<products> array) {
        System.out.println("--------------PRODUCTS IN STOCK!--------------");
        if (!array.isEmpty()) {
            for (int i = 0; i < array.size(); i++) {
                System.out.print("Product " + (i + 1) + ": ");
                array.get(i).displayInfo();
            }
        } else {
            System.out.println("The stock is empty\n");
        }
    }
}

