/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Symmetric;

import java.math.*;
import java.math.BigInteger;
import java.security.KeyFactory;
import java.security.interfaces.RSAPrivateKey;
import java.security.interfaces.RSAPublicKey;
import java.security.spec.RSAPrivateKeySpec;
import java.security.spec.RSAPublicKeySpec;
import javax.crypto.Cipher;
import java.security.KeyPairGenerator;
import java.security.SecureRandom;
import java.util.Random;
import java.security.PublicKey;
import java.security.PrivateKey;
import java.security.KeyPair;
import java.security.Key;
import javax.crypto.SecretKey;
import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.SecretKeySpec;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.io.ByteArrayOutputStream;

public class RSA1 {
     public static void main(String[] args) throws Exception{
         
         BigInteger p,q,pMinus1,qMinus1,ph1,d,n; //변수 생성
         BigInteger e=BigInteger.valueOf(65537);  //e값 지정
         int certainty=200;  //200이상인 certainty 생성 
         SecureRandom rand=SecureRandom.getInstance("SHA1PRNG");
         do{
             p=new BigInteger(1024,certainty,rand);   //p에 1024비트를 주었다
             pMinus1=p.subtract(BigInteger.ONE);   //(p-1)
         }while(!(pMinus1.gcd(e).equals(BigInteger.ONE)));  //(e,p-1)=1
         
         do{
             q=new BigInteger(1024,certainty,rand);   //q에 1024비트를 주었다
             qMinus1=q.subtract(BigInteger.ONE);   //q-1
         }while(!(qMinus1.gcd(e).equals(BigInteger.ONE)));  //(e,q-1)=1  
         ph1=pMinus1.multiply(qMinus1);   //(p-1)*(q-1)=Φ(n)
         n=p.multiply(q);
         d=e.modInverse(ph1);
         System.out.println("p = "+p.toString());
         System.out.println("q=  "+q.toString());
         System.out.println("n= "+n.toString()); 
           System.out.println("e = "+e.toString());
             System.out.println("d = "+d.toString());
         
         // p와 q를 생성    e와 d를 생성   certainty는 200으로 설정 
         //BigInteger를 사용해서 생성 후 각각 do-while문을 사용해서 각 수식을 구현한다.
         // n은 p와 q의 곱셈 그리고 d는 Φ(n)를 이용해서 도출해냄 
         // e는 65537로 설정하여서 계산함 
 
         
         byte[] desKeyData= 
        {(byte)0x01,(byte)0x02,(byte)0x03,(byte)0x04,(byte)0x05,(byte)0x06,(byte)0x07,(byte)0x08};
         SecretKeySpec deskey=new SecretKeySpec(desKeyData,"DES");
         SecretKeyFactory factory = SecretKeyFactory.getInstance("DES");
         SecretKey secretKey=factory.generateSecret(deskey);
         //DES암호로 Secretkey를 생성한다
         
         byte [] plainText = "My name is KimJaeHyun".getBytes();
         for(int i=0;i<plainText.length;i++){
            System.out.print(plainText[i]+ " ");
        }           //처음에 평문이 어떤식인지 출력한다 최종적으로 마지막에 출력되는 복호화 된 평문과 비교해본다 
         System.out.println();
         Cipher cipher=Cipher.getInstance("DES");
         cipher.init(Cipher.ENCRYPT_MODE,secretKey);  //DES대칭키로 평문을 암호화 한다.
         byte[] cipherText=cipher.doFinal(plainText);
         for(int i=0;i<cipherText.length;i++){
             System.out.print(cipherText[i]+" ");  //암호화 한 평문을 출력해서 암호화가 되었는지 확인해본다 
         }
         // 대칭키 생성 후 DES암호를 통해서 평문을 암호화 시키는 작업 
         
         KeyFactory keyFactory = KeyFactory.getInstance("RSA");
         RSAPublicKeySpec pubKeySpec=new RSAPublicKeySpec(n,e);  //위에서 만든 n과 e로 pubKeySpec을 만든다
         RSAPrivateKeySpec privKeySpec=new RSAPrivateKeySpec(n,d);  //위에서 만든 n과 d로 privKeySpec을 만든다
         RSAPublicKey pubKey=(RSAPublicKey)keyFactory.generatePublic(pubKeySpec);  //KeySpec을 KeyObject로 변환한다
         RSAPrivateKey privKey=(RSAPrivateKey)keyFactory.generatePrivate(privKeySpec); //KeySpec을 KeyObject로 변환한다
        
     
         //RSA공개키, 개인키 생성 
        
         byte[] input=secretKey.getEncoded();  //대칭키를 byte단위로 변환하는 작업
         
         Cipher cipher2=Cipher.getInstance("RSA");
         cipher2.init(Cipher.ENCRYPT_MODE, pubKey);
         byte[] lol=cipher2.doFinal(input);   //byte단위로 변환한 대칭키를 암호화하였다. 
         
         //RSA공개키를 사용해서 DES 대칭키 secretKey를 암호화함 
         
        FileOutputStream outFile=new FileOutputStream("Mypublic");  //"Mypublic"라는 파일에 암호화 한 DES대칭키를 저장해 놓는다.
        outFile.write(lol);
        outFile.close();
        //암호화 된 DES대칭키를 외부파일로 저장한다. 
        
        
        FileInputStream fos=new FileInputStream("Mypublic");
        ByteArrayOutputStream baos=new ByteArrayOutputStream( );
        int theByte=0;
        while((theByte=fos.read())!=-1){
            baos.write(theByte);
        }
        fos.close();
        byte[] lol2=baos.toByteArray();  //lol2라는 byte에 파일을 읽어드린다. 
        baos.close();  //파일을 열어서 암호화 된 DES키를 얻어내는 작업
        
        cipher2.init(Cipher.DECRYPT_MODE, privKey);   //얻어낸 DES키를 복호화하는 작업
        byte[] descre=cipher2.doFinal(lol2);
        //암호화 된 DES대칭키를 외부파일로부터 읽어봐서 저장 후 개인키로 복호화하여서 DES대칭키를 얻어낸다. 
        
        
        SecretKeySpec deskey2=new SecretKeySpec(descre,"DES");
        SecretKeyFactory factory2=SecretKeyFactory.getInstance("DES");
        SecretKey secretKey2=factory2.generateSecret(deskey2);
        
        //Byte화 된 DES 대칭키를 다시 새로운 key를 생성해서 그 안에 DES대칭키 자료를 집어넣는다
        
        Cipher cipher3=Cipher.getInstance("DES");
        cipher3.init(Cipher.DECRYPT_MODE, secretKey2);
        byte[] data2=cipher3.doFinal(cipherText);
       // 새로운 secretKey2로 암호화 된 cipherText를 복호화한다. 
       
        System.out.println();
        for(int i=0;i<data2.length;i++){
            System.out.print(data2[i]+ " ");
        }
       //복호화 된 data2를 출력해서 처음에 plaintext와 일치하는지 확인해본다    
     }
}
