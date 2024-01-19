package cps2004.java;

public class transportFactory {
    public transport createtransportFactory(String type,String name, double speed, double cost, String route){
        if(type.equalsIgnoreCase("truck")){
            return new truck(name,speed,cost,route);
        }else if(type.equalsIgnoreCase("ship")){
            return new ship(name,speed,cost,route);
        }else if(type.equalsIgnoreCase("aircraft")){
            return new aircraft(name,speed,cost,route);
        }
        throw new IllegalArgumentException("Invalid transport type: " + type);
    }   
}
