/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Symmetric;
import java.math.BigInteger;
/**
 *
 * @author User
 */
public class NewClass {
    public static void main(String[] args) throws Exception{
        BigInteger p=BigInteger.valueOf(997);
        
        BigInteger g=BigInteger.valueOf(7); //임의의 생성자가 아닌 32을 가지고 실행
         
        BigInteger y=BigInteger.valueOf(17);  //y는 27이다 
        BigInteger k=BigInteger.ZERO;    //k에 0을 집어넣어서 초기화한다 (x값을 구할 변수)
        BigInteger z=BigInteger.valueOf(1);  //z는 y와 비교할 변수이다
        do{
           k=k.add(BigInteger.valueOf(1));  //하나씩 증가하면서 전수조사를 시작한다
           z=g.modPow(k, p);  //z에 전수조사를 하면서 z값과 y값이 같아지는 순간을 조사한다
        }while(!z.equals(y)); //같아지면 끝난다 
      System.out.println("전수조사 결과 x는 : "+k);  //while문이 종료된 후 x의 값을 구할 수 있다
    }
}
