Write a Java program that implements a multi-threaded program which has three threads.
First thread generates a random integer every 1 second. If the value is even, second
thread computes the square of the number and prints. If the value is odd the third thread
will print the value of cube of the number
import java.util.Random;
class EvenThread extends Thread{
private int num;
public EvenThread(int num){
this.num = num;
}
public void run(){
System.out.println("Square of"+ num+"="+num*num);
}
}
class OddThread extends Thread{
private int num;
public OddThread(int num){
this.num = num;
}
public void run(){
System.out.println("Cube of "+num+"="+ num*num*num);
}
}
class RandomThread extends Thread{
public void run(){
Random r = new Random();
for(int i =0;i<10;i++){
int num = r.nextInt(100);
if(num % 2 == 0){
new EvenThread(num).start();
}
else{
new OddThread(num).start();
}
}
}
}
class Test{public static void main(String args[]){
RandomThread r = new RandomThread();
r.start();
}
}
/*
class EvenThread extends Thread{
private int num;
public EvenThread(int num){
this.num = num;
}
public void run(){
System.out.println(num*num);
}
}
*/
