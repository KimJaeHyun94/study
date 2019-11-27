/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Symmetric;

import java.math.BigInteger;

public class DLP {
     public static void main(String[] args) throws Exception{
        BigInteger p=BigInteger.valueOf(23);
        BigInteger g=BigInteger.valueOf(5);
        BigInteger i=BigInteger.valueOf(0);
        BigInteger x=BigInteger.ZERO;
        BigInteger result;
        System.out.println("p ="+p);
         do{
          x=x.add(BigInteger.valueOf(1));     //1부터 하나씩 증가시키면서 23에대해서 위수를 구한다
          result=BigInteger.valueOf(0);   //초기화한다
          i=BigInteger.valueOf(0);  // i를 초기화 해서 1부터 곱해나간다
         do{
        i=i.add(BigInteger.valueOf(1));    
        result=x.modPow(i, p);    //위수를 구한다 
       }while(!(result.equals(BigInteger.ONE)));
         System.out.println(x+" "+i);  //각각의 수에 위수를 출력한다 
        }while(!x.equals(p));    //소수이므로 자기보다 작은 수까지 모두 구성원소이다 
     }
}