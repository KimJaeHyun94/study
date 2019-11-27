/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Symmetric;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import javax.crypto.Cipher;
import javax.crypto.SecretKey;
import javax.crypto.KeyGenerator;
import java.security.SecureRandom;
import javax.crypto.spec.IvParameterSpec;
public class ENPFileEncryption {
    public static void main(String[] args) throws Exception{
        
        KeyGenerator keyGeneartor=KeyGenerator.getInstance("AES");
        keyGeneartor.init(new SecureRandom());
        SecretKey secretKey=keyGeneartor.generateKey();
    
        FileInputStream InFile=new FileInputStream("test.bmp");
        FileOutputStream outFile=new FileOutputStream("암호화 test.bmp");

        byte[] ivBytes=new byte[]
        {0x00,0x01,0x02,0x03,0x00,0x00,0x00,0x01};
        IvParameterSpec ivSpec=new IvParameterSpec(ivBytes);
        Cipher cipher=Cipher.getInstance("AES/CTR/NoPadding");
        cipher.init(Cipher.ENCRYPT_MODE,secretKey);
        
        byte[] input =new byte[64];
        int bytesRead;
        while((bytesRead=InFile.read(input))!=-1){
            byte[] output =cipher.update(input, 0, bytesRead);
            if(output !=null)
                outFile.write(output);
        }
        byte[] output=cipher.doFinal();
        if(output!=null)
            outFile.write(output);
        
        InFile.close();
        outFile.flush();
        outFile.close();
        }
     }
    
