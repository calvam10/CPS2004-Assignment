package cps2004.java;


class BookFactory{
    public products createProduct(String name, double price, String supplier,int packagingUnits, String author, String genre, int year){
        return new book(name,price,supplier,packagingUnits,author,genre,year);
    }
}

class ClothingFactory{
    public products createProduct(String name, double price, String supplier,int packagingUnits, String brand, char size, String color){
        return new clothing(name,price,supplier,packagingUnits,brand,size,color);
    }
}

class ComputerGamesFactory{
    public products createProduct(String name, double price, String supplier,int packagingUnits, String company, String console, int age){
        return new computergames(name,price,supplier,packagingUnits,company,console,age);
    }

}

class ElectronicsFactory{
    public products createProduct(String name, double price, String supplier,int packagingUnits, String brand, String place, int power){
        return new electronics(name,price,supplier,packagingUnits,brand,place,power);
    }
}

class FurnitureFactory{
    public products createProduct(String name, double price, String supplier,int packagingUnits, String material, String dimension, String style){
        return new furniture(name,price,supplier,packagingUnits,material,dimension,style);
    }
}

class JewelryFactory{
    public products createProduct(String name, double price, String supplier,int packagingUnits, String material, String gemstone, String design){
        return new jewelry(name,price,supplier,packagingUnits,material,gemstone,design);
    }
}

