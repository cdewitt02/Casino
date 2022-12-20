import java.util.Scanner;
public class TempConverter {
    public static void main(String[] args) {

        Scanner in_val = new Scanner(System.in);
        Scanner in_type = new Scanner(System.in);
        Scanner out_type = new Scanner(System.in);
        double output;


        System.out.println("Enter temperature value :");

        double val = in_val.nextDouble();


        System.out.println("Enter temperature unit (F, C, K):");

        String type1 = in_type.nextLine();

        System.out.println("What unit will you convert too? (F, C, K):");

        String type2 = out_type.nextLine();

        if(type2.equals("F")){
           output = to_f(val, type1);
           System.out.println(output + " degrees Fahrenheit");
        }
        else if(type2.equals("C")){
            output = to_c(val, type1);
            System.out.println(output + " degrees Celsius");
        }
        else if(type2.equals("K")){
            output = to_k(val, type1);
            System.out.println(output+ " degrees Kelvin");
        }
        else{
            System.out.println("Invalid type");
        }




    }

    public static double to_f(double val, String type1){
        if(type1.equals("F")){
            return val;
        }
        if(type1.equals("C")){
            return ((val * 1.8) + 32);
        }
        if(type1.equals("K")){
            return ((val-273.15) * 1.8) + 32;
        }
        return 0.0;
    }
    public static double to_c(double val, String type1){
        if(type1.equals("F")){
            return (val - 32) * (5/9);
        }
        if(type1.equals("C")){
            return val;
        }
        if(type1.equals("K")){
            return (val-273.15);
        }
        return 0.0;
    }
    public static double to_k(double val, String type1){
        if(type1.equals("F")){
            return ((val - 32) * (5/9)) + 273.15;
        }
        if(type1.equals("C")){
            return val + 273.15;
        }
        if(type1.equals("K")){
            return val;
        }
        return 0.0;
    }

}