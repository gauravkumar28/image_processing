import java.awt.image.BufferedImage;
import java.io.ByteArrayOutputStream;
import java.io.File;
import javax.imageio.ImageIO;
import com.sun.org.apache.xerces.internal.impl.dv.util.Base64;
  
public class image_to_Byte {
  
public static void main(String args[]) {
try{
      BufferedImage image = ImageIO.read(new File("demo.png"));
      ByteArrayOutputStream baos = new ByteArrayOutputStream();
      ImageIO.write(image, "png", baos);
     byte[] res=baos.toByteArray();
      String encodedImage = Base64.encode(baos.toByteArray());
      System.out.println("The encoded image byte array is shown below.Please use this in your webpage image tag.\n"+encodedImage);
}
catch(Exception e) {
     e.printStackTrace();
System.out.println("Some problem has occurred. Please try again");
}
}
  
}


//Read more: http://mrbool.com/how-to-convert-image-to-byte-array-and-byte-array-to-image-in-java/25136#ixzz2roUbdIKu
