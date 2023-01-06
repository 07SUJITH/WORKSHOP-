import java.util.Scanner;

class Employee {
    String name;
    int age ;
    long phoneNumber;
    String address;
    float salary;
    Employee(String name,int age,long phoneNumber,String address,float salary){
        this.name=name;
        this.age=age;
        this.phoneNumber=phoneNumber;
        this.address=address;
        this.salary=salary;
    }
    public void printSalary(){
        System.out.println("salary : "+ salary);
    }
}
class Officer extends Employee{
    private String specialization;
    private String department;
    Officer(int age,long phoneNumber,float salary, String name,String address,String specialization,String department){
        super(name,age,phoneNumber,address,salary);

        this.specialization=specialization;
        this.department=department;
    }
    void printData(){
        System.out.println("Name : "+ name);
        System.out.println("Age :"+ age);
        System.out.println("Phone Number :"+ phoneNumber);
        System.out.println("Address :" + address);
        printSalary();
        System.out.println("Specialization : "+ specialization );
        System.out.println("Department :"+ department);
    }
}
class Manager extends Employee{
    private String specialization;
    private String department;
    Manager( int age,long phoneNumber,float salary, String name,String address,String specialization,String department){
        super(name,age,phoneNumber,address,salary);
        this.specialization=specialization;
        this.department=department;
       
    }
    void printData(){
        System.out.println("Name : "+ name);
        System.out.println("Age :"+ age);
        System.out.println("Phone Number :"+ phoneNumber);
        System.out.println("Address :" + address);
        printSalary();
        System.out.println("Specialization : "+ specialization );
        System.out.println("Department :"+ department);
        System.out.println();
    }
}

class TestInheritance{
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        System.out.println("Enter details of officer :\n1.age\n2.Phone number\n3.salary and name\n4.address\n5.specialization\n6.department\n");
        Officer  officer = new Officer(sc.nextInt(),sc.nextLong(),sc.nextFloat(),sc.nextLine(),sc.nextLine(),sc.nextLine(),sc.nextLine());
        System.out.println("OFFICER Deatils ");
        officer.printData();

        System.out.println("Enter details of Manager :\n1.age\n2.Phone number\n3.salary and name\n4.address\n5.specialization\n6.department\n");
        Manager  manager = new Manager(sc.nextInt(),sc.nextLong(),sc.nextFloat(),sc.nextLine(),sc.nextLine(),sc.nextLine(),sc.nextLine());
        System.out.println("MANAGER Deatils ");
        manager.printData();
    }
}
/*
 * 
 * 30
8865534546
50000 APPUKUTTAN
THOTTATHIL ULANPARA
AI       
Computer science
OFFICER Deatils
Name :  APPUKUTTAN
Age :30
Phone Number :8865534546
Address :THOTTATHIL ULANPARA
salary : 50000.0
Specialization : AI
Department :Computer science
Enter details of Manager :
1.age
2.Phone number
3.salary and name
4.address
5.specialization
6.department

21
4736547
40000 RAJU
RAJU BHAVAN
Networking
cs
MANAGER Deatils
Name :  RAJU
Age :21
Phone Number :4736547
Address :RAJU BHAVAN
salary : 40000.0
Specialization : Networking
Department :cs

*/
