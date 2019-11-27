/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Symmetric;

/**
 *
 * @author User
 */
import java.security.SecureRandom;
import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;

public class symmetricl {
    public static void main(String[] args) throws Exception{
         KeyGenerator keyGeneartor=KeyGenerator.getInstance("DES");
        keyGeneartor.init(new SecureRandom());
        SecretKey secretKey=keyGeneartor.generateKey();
        byte[] plainText="This is a Piaintext".getBytes();
        
        System.out.println(7+" ");
        
        Cipher cipher=Cipher.getInstance("DES/ECD/PKCS5Padding");
        cipher.init(Cipher.ENCRYPT_MODE,secretKey);
       
            
    }
    
    
}
