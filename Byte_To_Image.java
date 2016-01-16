import java.awt.image.BufferedImage;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;

 
 
public class Byte_To_Image {
	public static void main(String[] args) throws IOException{
		BufferedImage image = ImageIO.read(new File("demo.png"));
      ByteArrayOutputStream baos = new ByteArrayOutputStream();
      ImageIO.write(image, "png", baos);
		//baos.flush();
 
		
		
 
		byte[] bytearray = baos.toByteArray();
baos.close();
 
		BufferedImage imag=ImageIO.read(new ByteArrayInputStream(bytearray));
		ImageIO.write(imag, "jpg", new File("snap.jpg"));
	}
}
