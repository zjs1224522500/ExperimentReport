package SimpleWebServer;

import java.io.OutputStream;
import java.util.Date;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileInputStream;
import java.io.BufferedReader;
import java.io.File;


public class Response {
    private static final int BUFFER_SIZE = 1024;
    Request request = null;
    OutputStream output = null;   
    public Response(OutputStream output) {
        this.output = output;
    }
    public void setRequest(Request request) {
        this.request = request;
    }
    public void sendStaticResource() throws IOException {
    	// 创建字节数组
        byte[] bytes = new byte[BUFFER_SIZE];
        // 文件输入流
        FileInputStream fis = null;
        try {
            //将 uri 对应的要访问的web文件写入到OutputStream字节流中
            File file = new File(WebServer.WEB_ROOT, request.getUri());
            if (file.exists()) {
                fis = new FileInputStream(file);
                BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(fis));
                String readData = null;  
                System.out.println("响应报文：\r\n");  
                while ((readData = bufferedReader.readLine()) != null)  
                {  
                    System.out.println(readData);  
                }

                // ch 为读取到的字节数，循环每次读取 1024/8=128 个字节数据到相应的文件输入流中
                int ch = fis.read(bytes, 0, BUFFER_SIZE);
                while (ch != -1) {
                    output.write(bytes, 0, ch);
                    ch = fis.read(bytes, 0, BUFFER_SIZE);
                }
            } else {
                // 如果要访问的文件不存在，则将错误信息对应的响应报文写入到输出流中
                String errorMessage = "HTTP/1.1 404 File Not Found\r\n" + "Content-Type: text/html\r\n"
                        + "Content-Length: 23\r\n" + "\r\n" + "<h1>File Not Found</h1>";
                output.write(errorMessage.getBytes());
            }
        } catch (Exception e) {
        	 // thrown if cannot instantiate a File object
            System.out.println(e.toString());
        } finally {
        	// 最后关闭相应的文件输入流
            if (fis != null)
                fis.close();
        }
    }
}
        
