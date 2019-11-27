/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Symmetric;

import java.security.SecureRandom;
public class randomGen {
    public static void main(String [] args ) throws Exception{
        SecureRandom sr=new SecureRandom();
        byte[] pseudorandom=new byte[20];
        sr.nextBytes(pseudorandom);
        
        for(int i=0;i<pseudorandom.length; i++){
            System.out.print(pseudorandom[i]+" ");
        }
                
         }
    
}
