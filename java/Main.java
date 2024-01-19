package cps2004.java;

import java.util.ArrayList;
import java.util.Scanner;


public class Main {
    
    static ArrayList<products> list = new ArrayList<>();
    static ArrayList<transport> transports = new ArrayList<>();
    static ArrayList<packaging> packagings = new ArrayList<>();
    static ArrayList<customer> customers = new ArrayList<>();
    static ArrayList<shipment> shipments = new ArrayList<>();
    static stock stock = new stock();


    public static void main(String[] args){

        while(true){
            menu();
        }
    }

    public static void menu(){
        Scanner scanner = new Scanner(System.in);

        System.out.println("------------------LOGISTIC MANAGEMENT APPLICATION------------------");
        System.out.println("1-Create/Read/Update/Delete Products");
        System.out.println("2-Create/Read/Update/Delete Means of Transport");
        System.out.println("3-Create/Read/Update/Delete Packaging");
        System.out.println("4-Create/Read/Update/Cancel Shipments");
        System.out.println("5-Create a new Customer");
        System.out.println("6-Calculate total price for a shipment");
        System.out.println("7-Save/Restore application");
        System.out.println("8-Exit");

        System.out.print("Please, enter the desired value: ");
        try{
            int option = Integer.parseInt(scanner.nextLine());
            switch (option) {
                case 1:
                    System.out.print("\033[2J\033[H");  //This is for clean the terminal
                    System.out.println("Introduced option 1: Managing Products");
                    menuProducts();
                    break;

                case 2:
                    System.out.print("\033[2J\033[H");  //This is for clean the terminal
                    System.out.println("Introduced option 2: Managing Means of Transport");
                    menuMeansTransport();
                    break;

                case 3:
                    System.out.print("\033[2J\033[H");  //This is for clean the terminal
                    System.out.println("Introduced option 3: Managing Packaging");
                    menuPackaging();
                    break;

                case 4:
                    System.out.print("\033[2J\033[H");  //This is for clean the terminal
                    System.out.println("Introduced option 4: Managing Shipments");
                    menuShipments();
                    break;

                case 5:
                    System.out.print("\033[2J\033[H");  //This is for clean the terminal
                    System.out.println("Introduced option 5: Create a new Customer");
                    menuCustomers();
                    break;
                case 6:
                    System.out.print("\033[2J\033[H");  //This is for clean the terminal
                    System.out.println("Introduced option 6: Calculate Total Price for a Shipment");
                    calculateTotalPriceShipment();
                    break;

                case 7:
                    System.out.print("\033[2J\033[H");  //This is for clean the terminal
                    System.out.println("Introduced option 7: Save/Restore Application State");
                    break;
            

                case 8:
                    System.out.print("\033[2J\033[H");  //This is for clean the terminal
                    System.out.println("Entered exit value, goodbye!");
                    System.exit(0);
                    break;

                default:
                    System.out.println("The value entered does not correspond to any function in the menu, try again\n\n");
                    break;
            }
        } catch(NumberFormatException e){
            System.out.println("Introduce a valid number!\n");
        }
    } 

    public static void menuProducts() { //Option 1
        Scanner scanner = new Scanner(System.in);
        System.out.println("1-Create a new Product");
        System.out.println("2-Read Products");
        System.out.println("3-Update a Product");
        System.out.println("4-Delete a Product");
        System.out.print("Please, enter the desired value: ");

        String option = scanner.nextLine();
        int aux = 0;

        if(option.isEmpty()){
            System.out.println("Error: Please enter a valid number!!\n");
        }else{
            aux = Integer.parseInt(option);
            switch (aux) {
                case 1: //Create
                    String name, supplier;
                    double price;
                    int quantity;
                    System.out.print("\nIntroduce the name of the Product: ");
                    name = scanner.nextLine();
                    System.out.print("\nEnter the price of the product: ");
                    price = scanner.nextDouble();
                    scanner.nextLine(); // consume the newline character
                    System.out.print("\nEnter the supplier: ");
                    supplier = scanner.nextLine();
                    System.out.print("\nEnter the quantity of the new product created: ");
                    quantity = scanner.nextInt();

                    menuTypeProducts();
                    String type;
                    System.out.print("Select the type of the product: ");
                    type = scanner.next();
                    switch (type) {
                        case "1":
                            BookFactory test1 = new BookFactory();
                            String author,genre;
                            int year;
                            System.out.print("\nEnter the author of the book: ");
                            scanner.nextLine(); // consume the newline character
                            author = scanner.nextLine();

                            System.out.print("\nEnter the genre of the book: ");
                            genre = scanner.nextLine();

                            System.out.print("\nEnter the year of the publication of the book: ");
                            year = scanner.nextInt();

                            /*book book = new book(name, price, supplier, quantity, author, genre, year);
                            book.displayInfo();
                            stock.addProduct(book, list);
                            stock.displayStock(list);*/

                            
                            products productoTest1 = test1.createProduct(name, price, supplier, quantity, author, genre, year);
                            productoTest1.setPrice(productoTest1.calculateDiscount(quantity, 1));
                            stock.addProduct(productoTest1, list);

                            break;
                        case "2":
                            ClothingFactory test2 = new ClothingFactory();
                            String brand, color;
                            char size;

                            System.out.print("\nEnter the brand of the cloth: ");
                            scanner.nextLine(); // consume the newline character
                            brand = scanner.nextLine();
    
                            System.out.print("\nEnter the size of the cloth: ");
                            size = scanner.next().charAt(0);
    
                            System.out.print("\nEnter the color of the cloth: ");
                            scanner.nextLine(); // consume the newline character
                            color = scanner.nextLine();
    
                            /*clothing clothing = new clothing(name, price, supplier, quantity, brand, size, color);
                            clothing.displayInfo();
                            stock.addProduct(clothing, list);*/

                            products productoTest2 = test2.createProduct(name, price, supplier, quantity, brand, size, color);
                            stock.addProduct(productoTest2, list);
                            break;
                            
                        case "3": 
                            ComputerGamesFactory test3 = new ComputerGamesFactory();
                            String company, console;
                            int age;
    
                            System.out.print("\nEnter the company of the computer game: ");
                            scanner.nextLine(); // consume the newline character
                            company = scanner.nextLine();
    
                            System.out.print("\nEnter the console of the computer game: ");
                            console = scanner.nextLine();
    
                            System.out.print("\nEnter the minimum age to play this game: ");
                            age = scanner.nextInt();
    
                            /*computergames computer_games = new computergames(name, price, supplier, quantity, company, console, age);
                            computer_games.displayInfo();
                            stock.addProduct(computer_games, list);
                            stock.displayStock(list);*/

                            products productoTest3 = test3.createProduct(name, price, supplier, quantity, company, console, age);
                            stock.addProduct(productoTest3, list);

                            break;
                            
                        case "4": 
                            ElectronicsFactory test4 = new ElectronicsFactory();
                            String brand2, placeOfManufacture;
                            int power;
    
                            System.out.print("\nEnter the brand of the electronic: ");
                            scanner.nextLine(); // consume the newline character
                            brand2 = scanner.nextLine();
    
                            System.out.print("\nEnter the place of manufacture of the electronic: ");
                            placeOfManufacture = scanner.nextLine();
    
                            System.out.print("\nEnter the power of the electronic: ");
                            power = scanner.nextInt();
    
                            /*electronics electronic = new electronics(name, price, supplier, quantity, brand2, placeOfManufacture, power);
                            electronic.displayInfo();
                            stock.addProduct(electronic, list);
                            stock.displayStock(list);*/

                            products productoTest4 = test4.createProduct(name, price, supplier, quantity, brand2, placeOfManufacture, power);
                            stock.addProduct(productoTest4, list);
                            break;
                            
                        case "5": 
                            FurnitureFactory test5 = new FurnitureFactory();
                            String material, dimensions, style;
    
                            System.out.print("\nEnter the material of the furniture: ");
                            scanner.nextLine(); // consume the newline character
                            material = scanner.nextLine();
    
                            System.out.print("\nEnter the dimensions of the furniture: ");
                            dimensions = scanner.nextLine();
    
                            System.out.print("\nEnter the style of the furniture: ");
                            style = scanner.nextLine();
    
                            /*furniture furniture = new furniture(name, price, supplier, quantity, material, dimensions, style);
                            furniture.displayInfo();
                            stock.addProduct(furniture, list);
                            stock.displayStock(list);*/
    
                            products productoTest5 = test5.createProduct(name, price, supplier, quantity, material, dimensions, style);
                            stock.addProduct(productoTest5, list);

                            break;
                            
                        case "6": 
                            JewelryFactory test6 = new JewelryFactory();
                            String material2, gemstone, design;
    
                            System.out.print("\nEnter the material of the furniture: ");
                            scanner.nextLine(); // consume the newline character
                            material2 = scanner.nextLine();
    
                            System.out.print("\nEnter the dimensions of the furniture: ");
                            gemstone = scanner.nextLine();
    
                            System.out.print("\nEnter the style of the furniture: ");
                            design = scanner.nextLine();
    
                            /*jewelry jewelry = new jewelry(name, price, supplier, quantity, material2, gemstone, design);
                            jewelry.displayInfo();
                            stock.addProduct(jewelry, list);
                            stock.displayStock(list);*/

                            products productoTest6 = test6.createProduct(name, price, supplier, quantity, material2, gemstone, design);
                            stock.addProduct(productoTest6, list);
                            break;
                    
                        default:
                            break;
                    }


                    break;

                case 2: //Read
                    stock.displayStock(list);
                    break;

                case 3: //Update
                    Scanner scan = new Scanner(System.in);
                    if (list.isEmpty()) {
                        System.out.println("--------------PRODUCTS IN STOCK!--------------");
                        System.out.println("There is no products to modify!\n");
                    } else {
                        int p;
                        stock.displayStock(list);
                        System.out.print("Please, enter the number of the product to modify: ");
                        p = scanner.nextInt();
                        String a, c;
                        double b;
                        int d;

                        System.out.print("\nIntroduce the name of the Product: ");
                        a = scan.nextLine();
                        System.out.print("\nEnter the price of the product: ");
                        b = scanner.nextDouble();
                        System.out.print("\nEnter the supplier: ");
                        c = scan.nextLine();
                        System.out.print("\nEnter the quantity of the new product created: ");
                        d = scanner.nextInt();
                        list.get(p - 1).setName(a);
                        list.get(p - 1).setPrice(b);
                        list.get(p - 1).setSupplier(c);
                        list.get(p - 1).setPackagingUnits(d);

                        System.out.println("\n\n\n\n STOCK MODIFIED CORRECTLY!\n");
                        stock.displayStock(list);
                }
                    break;

                case 4: //Delete
                    if (list.isEmpty()) {
                        System.out.println("\n--------------PRODUCTS IN STOCK!--------------");
                        System.out.println("There is no products created, so we cannot delete one!\n");
                    } else {
                        int p;
                        stock.displayStock(list);
                        System.out.print("\n\n\nPlease, enter the number of the product to modify: ");
                        p = scanner.nextInt();
                        int rest;
                        System.out.print("\nEnter the number of units to be reduced from the object: ");
                        rest = scanner.nextInt();
                        stock.deleteProduct(p - 1, rest, list);

                        stock.displayStock(list);
                    }
                    break;

                default:
                    System.out.println("Value entered not valid\n");
                    break;
            }
        }
    }

    public static void menuMeansTransport() {   //Option 2
        System.out.println("1-Create a new Mean of Transport");
        System.out.println("2-Read Means of Transport");
        System.out.println("3-Update a Mean of Transport");
        System.out.println("4-Delete a Mean of Transport");
        System.out.print("Please, enter the desired value: ");
        Scanner scanner = new Scanner(System.in);
        String option = scanner.nextLine();
        int aux = 0;

        if (option.isEmpty()) {
            System.out.println("Error: Please enter a valid number!!\n\n");
        }

        aux = Integer.parseInt(option);

        switch (aux) {
            case 1: {    // Create
                String name;
                double speed,cost;
        
                System.out.print("\nEnter the name of the new Mean of Transport: ");
                name = scanner.nextLine();
                System.out.print("\nEnter the speed of the new Mean of Transport in km/h: ");
                speed = scanner.nextDouble();
                System.out.print("\nEnter the cost of the new Mean of Transport in euro per km: ");
                cost = scanner.nextDouble();

                menuTransports();

                System.out.print("Select the type of the transport: ");
                int option2 = scanner.nextInt();
                transportFactory test = null;
                switch (option2) {
                    case 1:// Truck
                        test = new transportFactory();
                        transport newTransportTruck = test.createtransportFactory("truck", name, speed, cost, "National Route");
                        newTransportTruck.addTransport(newTransportTruck, transports);
                        /*truck truck = new truck(name, speed, cost,"National Route");
                        truck.displayTruckInfo();
                        truck.addTransport(truck, transports);
                        System.out.println("Added Correctly!\n");*/
                        break;
                    case 2:  // Ship
                        test = new transportFactory();
                        transport newTransportShip = test.createtransportFactory("ship", name, speed, cost, "Mediterranean Route");
                        newTransportShip.addTransport(newTransportShip, transports);
                        /*
                        ship ship = new ship(name, speed, cost,"Mediterranean Route");
                        ship.displayShipInfo();
                        ship.addTransport(ship, transports);
                        System.out.println("Added Correctly!\n");*/
                        break;
                    case 3: // Aircraft
                        test = new transportFactory();
                        transport newTransportAircraft = test.createtransportFactory("aircraft", name, speed, cost, "International Route");
                        newTransportAircraft.addTransport(newTransportAircraft, transports);
                        /*
                        aircraft aircraft = new aircraft(name, speed, cost,"International Route");
                        aircraft.addTransport(aircraft, transports);
                        aircraft.displayAircraftInfo();
                        System.out.println("Added Correctly!\n");*/
                        break;
                    default:
                        System.out.println("Input not valid, resetting menu\n\n\n");
                        break;
                }
                break;
            }

            case 2: // Read2
                System.out.println("\n------------------------MEANS OF TRANSPORT------------------------\n");
                if (transports.isEmpty()) {
                    System.out.println("There is no means of transport created!\n");
                } else {
                    for (int i = 0; i < transports.size(); i++) {
                        System.out.println("Transport " + (i + 1) + ":");
                        transports.get(i).displayInfo(transports.get(i));
                    }
                }
                break;

            case 3: { // Update
                System.out.println("\n------------------------MEANS OF TRANSPORT------------------------\n");
                if (transports.isEmpty()) {
                    System.out.println("There is no means of transport to modify!\n\n");
                } else {
                    int p;

                    for (int i = 0; i < transports.size(); i++) {
                        System.out.println("Transport " + (i + 1) + ":");
                        transports.get(i).displayInfo(transports.get(i));
                    }

                    System.out.print("Please, enter the number of the mean of transport to modify: ");
                    p = scanner.nextInt();
                    String a;
                    double b, c;
                    System.out.print("\nIntroduce the name of the mean of transport: ");
                    a = scanner.next();
                    System.out.print("\nEnter the speed of the mean of transport: ");
                    b = scanner.nextDouble();
                    System.out.print("\nEnter the cost of the mean of transport: ");
                    c = scanner.nextDouble();

                    transports.get(p - 1).setName(a);
                    transports.get(p - 1).setSpeed(b);
                    transports.get(p - 1).setCost(c);

                    System.out.println("\n\n\n\n MEAN OF TRANSPORT MODIFIED CORRECTLY!\n");
                    System.out.println("\n------------------------MEANS OF TRANSPORT------------------------\n");

                    for (int i = 0; i < transports.size(); i++) {
                        System.out.println("Transport " + (i + 1) + ":");
                        transports.get(i).displayInfo(transports.get(i));
                    }
                }
                break;
            }

            case 4: // Delete
                System.out.println("\n------------------------MEANS OF TRANSPORT------------------------\n");
                if (transports.isEmpty()) {
                    System.out.println("There is no means of transport created, so we cannot delete one!\n");
                    break;
                } else {
                    for (int i = 0; i < transports.size(); i++) {
                        System.out.println("Transport " + (i + 1) + ":");
                        transports.get(i).displayInfo(transports.get(i));
                        System.out.println("Route: " + transports.get(i).getRoute() + "\n");
                    }
                    int p;
                    System.out.print("Please, enter the number of the mean of transport to delete: ");
                    p = scanner.nextInt();
                    transports.get(p - 1).deleteTransport(transports, p);
                }
                break;

            default:
                System.out.println("Value entered not valid\n");
                break;
        }
    }

    public static void menuPackaging() {    //Option 3

        Scanner scanner = new Scanner(System.in);
        System.out.println("1-Create a new Packaging");
        System.out.println("2-Read Packagings");
        System.out.println("3-Update a Packaging");
        System.out.println("4-Delete a Packaging");

        System.out.print("Please, enter the desired value: ");
        String option = scanner.nextLine();

        if (option.isEmpty()) {
            System.out.println("Error: Please enter a valid number!!\n");
            return;
        }

        int aux = Integer.parseInt(option);

        switch (aux) {
            case 1: // Create
                String packing;
                double cost;
                int capacity;

                System.out.print("\nEnter the name of the new Packing: ");
                packing = scanner.nextLine();

                System.out.print("\nEnter the cost of the new Packing: ");
                cost = scanner.nextDouble();

                System.out.print("\nEnter the capacity in terms of 'packaging units': ");
                capacity = scanner.nextInt();

                packaging newPackaging = new packaging(packing, cost, capacity);
                newPackaging.addPackaging(newPackaging, packagings);

                break;

            case 2: // Read
                System.out.println("\n------------------------PACKAGING------------------------\n");

                if (packagings.isEmpty()) {
                    System.out.println("There is no packagings created!\n");
                } else {
                    for (int i = 0; i < packagings.size(); i++) {
                        System.out.println("Packaging " + (i + 1) + ":  Name: " + packagings.get(i).getPacking() +
                                ", Id: " + packagings.get(i).getId() + ", Cost: " + packagings.get(i).getCost() +
                                ", Capacity: " + packagings.get(i).getCapacity() + "\n");
                    }
                }

                break;

            case 3: // Update
                System.out.println("\n------------------------PACKAGING------------------------\n");

                if (packagings.isEmpty()) {
                    System.out.println("There is no packagings to modify!\n\n");
                } else {
                    for (int i = 0; i < packagings.size(); i++) {
                        System.out.println("Packaging " + (i + 1) + ":  Name: " + packagings.get(i).getPacking() +
                                ", Id: " + packagings.get(i).getId() + ", Cost: " + packagings.get(i).getCost() +
                                ", Capacity: " + packagings.get(i).getCapacity() + "\n");
                    }

                    System.out.print("Please, enter the number of the packaging to modify: ");
                    int p = scanner.nextInt();
                    scanner.nextLine(); // Consume the newline character

                    System.out.print("\nEnter the name of the new Packing: ");
                    String x = scanner.next();

                    System.out.print("\nEnter the cost of the packaging: ");
                    double b = scanner.nextDouble();

                    System.out.print("\nEnter the capacity of the packaging: ");
                    int c = scanner.nextInt();



                    packagings.get(p - 1).setCost(b);
                    packagings.get(p - 1).setCapacity(c);
                    packagings.get(p - 1).setPacking(x);

                    System.out.println("\n------------------------PACKAGING------------------------\n");
                    for (int i = 0; i < packagings.size(); i++) {
                        System.out.println("Packaging " + (i + 1) + ":  Name: " + packagings.get(i).getPacking() +
                                ", Id: " + packagings.get(i).getId() + ", Cost: " + packagings.get(i).getCost() +
                                ", Capacity: " + packagings.get(i).getCapacity() + "\n");
                    }
                }

                break;

            case 4: // Delete
                System.out.println("\n------------------------PACKAGING------------------------\n");

                if (packagings.isEmpty()) {
                    System.out.println("There is no packagings created, so we cannot delete one!\n");
                    break;
                } else {
                    for (int i = 0; i < packagings.size(); i++) {
                        System.out.println("Packaging " + (i + 1) + ":  Name: " + packagings.get(i).getPacking() +
                                ", Id: " + packagings.get(i).getId() + ", Cost: " + packagings.get(i).getCost() +
                                ", Capacity: " + packagings.get(i).getCapacity() + "\n");
                    }

                    System.out.print("Please, enter the number of the mean of transport to delete: ");
                    int p = scanner.nextInt();
                    packagings.get(p - 1).deletePackaging(packagings, p-1);
                }

                break;

            default:
                System.out.println("Value entered not valid\n");
                break;
        }
    }

    public static void menuShipments() {    //Option 4
        Scanner scanner = new Scanner(System.in);
        ArrayList<products> productsShipment = new ArrayList<>();
        System.out.println("1-Create a new Shipment");
        System.out.println("2-Read Shipments");
        System.out.println("3-Update a Shipment");
        System.out.println("4-Cancel a Shipment");

        System.out.print("Please, enter the desired value: ");

        String option = scanner.nextLine();

        if (option.isEmpty()) {
            System.out.println("Error: Please enter a valid number!!\n\n");
            return;
        }

        int aux = Integer.parseInt(option);

        switch (aux) {
            case 1: // Create
            if (customers.isEmpty()) {
                System.out.println("There is not a customer created, so we cannot associate a shipment with a customer!\n");
            } else {
                for (int i = 0; i < customers.size(); i++) {
                    System.out.print("Customer " + (i+1) + ": ");
                    customers.get(i).displayInfo();
                }
    
                System.out.print("\n\nSelect the customer of the shipment: ");
                int s = scanner.nextInt();
    
                int x;
                int y;
    
                if (list.isEmpty()) {
                    System.out.println("There are no products in the stock, so we cannot add products to the shipment\n");
                } else {
                    do {
                        stock.displayStock(list);
                        System.out.print("\nEnter the product for the shipment. Type 0 to stop adding products to the shipment: ");
                        x = scanner.nextInt();
    
                        if (x == 0) {
                            break;
                        } else {
                            System.out.print("\nEnter the desired quantity of products for the shipment: ");
                            y = scanner.nextInt();
    
                            if (y > list.get(x - 1).getPackagingUnits()) {
                                System.out.println("\nThe value entered is greater than the number of product quantities, please try again.");
                                break;
                            } else {

                                products selectedProducts = list.get(x-1);
                                products productstoAdd = new products(selectedProducts.getName(),selectedProducts.getPrice(),selectedProducts.getSupplier(),y);
                                productsShipment.add(productstoAdd);
                                stock.deleteProduct(x - 1, y, list);
                            }
                        }
                    } while (x != 0);
    
                    System.out.println("\n------------------------PACKAGING------------------------\n");
                    double test = 0;

                    if (packagings.isEmpty()) {
                        System.out.println("There are no packagings, so we cannot associate one to a shipment!\n");
                    } else {
                        int capacity = 0;
                        for(int i=0;i<productsShipment.size();i++){
                            capacity += productsShipment.get(i).getPackagingUnits();
                        }
    
                        int control = 0;
    
                        do {
                            int h;
    
                            for (int i = 0; i < packagings.size(); i++) {
                                System.out.println("Packaging " + (i + 1) + ":  Name: " + packagings.get(i).getPacking() +
                                        ", Id: " + packagings.get(i).getId() + ", Cost: " + packagings.get(i).getCost() +
                                        ", Capacity: " + packagings.get(i).getCapacity() + "\n");
                            }
    
                            System.out.print("\nEnter the packaging for the shipment. Make sure to pack all the products!\n\n Remaining products to be packed: " + capacity + "\n");
                            h = scanner.nextInt();
    
                            control += packagings.get(h - 1).getCapacity();
                            test += packagings.get(h - 1).getCapacity()* packagings.get(h-1).getCost();
                            if (capacity > control) {
                                System.out.println("It iterates again because it doesn't reach, but subtracts");
                                capacity -= packagings.get(h - 1).getCapacity();
                            } else {
                                // It has passed/reached 0, so we set it to 0 and finish the packaging.
                                capacity = 0;
                            }
    
                        } while (capacity != 0);
                        if (transports.isEmpty()) {
                            System.out.println("There is no means of transport created, so we cannot associate one to a shipment!\n");
                        } else {
                            System.out.println("\n------------------------MEANS OF TRANSPORT EXISTING------------------------\n");
    
                            for (int i = 0; i < transports.size(); i++) {
                                System.out.println("Transport " + (i + 1) + ":");
                                transports.get(i).displayInfo(transports.get(i));
                            }
    
                            System.out.print("\nEnter the means of transport: ");
                            int n = scanner.nextInt();
    
                            shipment shipment = new shipment(customers.get(s - 1), transports.get(n - 1), productsShipment);
                            shipment.setTotalUnits(test);
                            shipments.add(shipment);
                            shipment.setTotalPrice(shipment.calculateProductsPrice()+shipment.calculateTransportCost()+shipment.getTotalUnits());
                        }
                    }
                }
            }
                break;

            case 2: // Read
                System.out.println("--------------SHIPMENT INFORMATION--------------\n");
                if (shipments.isEmpty()) {
                    System.out.println("There is no shipments!\n");
                } else {
                    for (int i = 0; i < shipments.size(); i++) {
                        System.out.println("--------------SHIPMENT " +  (i+1)+"--------------\n");
                        shipments.get(i).displayInfo();
                    }
                }
                break;

            case 3: // Update
                ArrayList<products> auxList = new ArrayList<>();
                System.out.println("----------SHIPMENT INFORMATION----------\n");
                if (shipments.isEmpty()) {
                    System.out.println("There is not a shipment to modify!\n\n");
                } else {
                    for (int i = 0; i < shipments.size(); i++) {
                        System.out.println("--------------SHIPMENT " +  (i+1)+"--------------\n");
                        shipments.get(i).displayInfo();
                    }

                    System.out.print("Select the shipment to modify: ");
                    int s = scanner.nextInt();

                    for (int i = 0; i < customers.size(); i++) {
                        System.out.print("Customer " + (i+1) + ": ");
                        customers.get(i).displayInfo();
                    }
        
                    System.out.print("\n\nSelect the customer of the shipment: ");
                    int x = scanner.nextInt();

                    System.out.println("\n------------------------MEANS OF TRANSPORT EXISTING------------------------\n");
    
                    for (int i = 0; i < transports.size(); i++) {
                        System.out.println("Transport " + (i + 1) + ":");
                        transports.get(i).displayInfo(transports.get(i));
                    }
                    System.out.print("\nEnter the means of transport: ");
                    int n = scanner.nextInt();

                    int y;
                    int z;
                    if (list.isEmpty()) {
                        System.out.println("There are no products in the stock, so we cannot add products to the shipment\n");
                    } else {
                        do {
                            stock.displayStock(list);
                            System.out.print("\nEnter the product for the shipment. Type 0 to stop adding products to the shipment: ");
                            z = scanner.nextInt();
    
                            if (z == 0) {
                                int totalDiscount = 0;
                                System.out.print("\nEnter a total discount for the shipment: ");
                                totalDiscount = scanner.nextInt();
                                shipmentDecorator shipmentDecorator = new DiscountDecorator(shipments.get(s-1),totalDiscount);
                                shipmentDecorator.displayInfo();
                                double discount = ((DiscountDecorator) shipmentDecorator).applyDiscount(shipments.get(s-1),totalDiscount);
                                shipments.get(s-1).updateShipments(auxList, customers.get(x-1), transports.get(n-1),discount);
                                break;
                            } else {
                                System.out.print("\nEnter the desired quantity of products for the shipment: ");
                                y = scanner.nextInt();
    
                                if (y > list.get(z - 1).getPackagingUnits()) {
                                    System.out.println("\nThe value entered is greater than the number of product quantities, please try again.");
                                    break;
                                } else { 
                                    products selectedProducts = list.get(z-1); 
                                    products productstoAdd = new products(selectedProducts.getName(),selectedProducts.getPrice(),selectedProducts.getSupplier(),y);
                                    stock.deleteProduct(z - 1, y, list);
                                    auxList.add(productstoAdd);

                                }
                                int totalDiscount = 0;
                                System.out.print("\nEnter a total discount for the shipment: ");
                                totalDiscount = scanner.nextInt();
                                shipmentDecorator shipmentDecorator = new DiscountDecorator(shipments.get(s-1),totalDiscount);
                                shipmentDecorator.displayInfo();
                                double discount = ((DiscountDecorator) shipmentDecorator).applyDiscount(shipments.get(s-1),totalDiscount);
                                shipments.get(s-1).updateShipments(auxList, customers.get(x-1), transports.get(n-1),discount);
                            }
                        } while (z != 0);
                    

                    }
                }
                break;

            case 4: // Cancel
                System.out.println("--------------SHIPMENTS INFORMATION--------------\n");
                if (shipments.isEmpty()) {
                    System.out.println("There is no shipments!\n");
                } else {
                    for (int i = 0; i < shipments.size(); i++) {
                        System.out.println("--------------SHIPMENT " +  (i+1)+"--------------\n");
                        shipments.get(i).displayInfo();
                    }

                    System.out.print("\nSelect the shipment to cancel: ");
                    int pos = scanner.nextInt();

                    if (shipments.get(pos - 1).isDispatched()) {
                        shipments.get(pos-1).setStatus("Already dispatched");
                        System.out.println("The shipment is already dispatched\n\n");
                    } else {
                        shipments.remove(pos - 1);
                        System.out.println("Shipment canceled!\n\n");
                    }
                }
                break;

            default:
                System.out.println("Value entered not valid\n");
                break;
        }
    }

    public static void menuCustomers() {    //Option 5
        Scanner scanner = new Scanner(System.in);
        String name;
        int age, distance;

        System.out.println("\nEnter the name of the new customer: ");
        name = scanner.nextLine();
        System.out.println("\nEnter the age of the customer: ");
        age = scanner.nextInt();
        System.out.println("\nEnter the distance of the customer: ");
        distance = scanner.nextInt();
        customer customer = new customer(name,age,distance);
        customers.add(customer);
    }

    public static void calculateTotalPriceShipment() {  //Option 6
        Scanner scanner = new Scanner(System.in);
        System.out.println("----------SHIPMENT INFORMATION----------\n");
        if (shipments.isEmpty()) {
            System.out.println("There is not a shipment to modify!\n\n");
        } else {
            for (int i = 0; i < shipments.size(); i++) {
                shipments.get(i).displayInfo();
            }

            System.out.print("Select the shipment to calculate its total price: ");
            int s = scanner.nextInt();
            System.out.println("Total price of the shipment: " + shipments.get(s-1).getTotalPrice());

        }
    }


    public static void menuTypeProducts(){  //Complementary menu of menuProducts()
        System.out.println("1-Book\n");
        System.out.println("2-Clothing\n");
        System.out.println("3-Computer Games\n");
        System.out.println("4-Electronics\n");
        System.out.println("5-Furniture\n");
        System.out.println("6-Jewelry\n");
    }

    public static void menuTransports(){    //Complementary menu of menuMeansTransport()
        System.out.println("1-Truck\n");
        System.out.println("2-Ship\n");
        System.out.println("3-Aircraft\n");
    }    
}