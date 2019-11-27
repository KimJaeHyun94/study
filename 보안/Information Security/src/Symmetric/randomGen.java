
package Symmetric;
import java.security.SecureRandom;
public class randomGen {
    public static void main(String[] args) throws Exception {
    
    SecureRandom sr=new SecureRandom();
    byte[] pseudorandom=new byte[20];
    
    sr.nextBytes(pseudorandom);
    
    for(int i=0;i<pseudorandom.length;i++){
    System.out.print(pseudorandom[i]+" ");
   }
    }
}
