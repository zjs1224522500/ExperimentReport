package SimpleWebServer;


import java.net.Socket;
import java.net.ServerSocket;
import java.net.InetAddress;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.File;

public class WebServer {
    public static final String WEB_ROOT = System.getProperty("user.dir") + File.separator + "WebContent";
    // 关闭服务命令
    private static final String SHUTDOWN_COMMAND = "/SHUTDOWN";   
    private String uri;
    public static void main(String[] args) {
        WebServer server = new WebServer();
        // 等待连接请求
        server.await();
    }
    public void await() {
    	// 声明服务器端套接字
        ServerSocket serverSocket = null;
        // 设置端口号
        int port = 8080;
        try {
            // 创建服务器套接字对象ServerSocket(int port, int backlog, InetAddress bindAddr)
            serverSocket = new ServerSocket(port, 1, InetAddress.getByName("127.0.0.1"));
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }

        // 循环等待一个请求
        while (true) {
            Socket socket = null;
            InputStream input = null;
            OutputStream output = null;
            try {
                // 等待连接，连接成功后，返回一个Socket对象   Socket java.net.ServerSocket.accept() 
                socket = serverSocket.accept();
                input = socket.getInputStream();
                output = socket.getOutputStream();
                // 创建Request对象并解析相应的请求报文  Request(InputStream inputStream)
                Request request = new Request(input);
                request.parse();             
                uri = request.getUri();           
                // 检查是否是关闭服务命令
                if(uri != null){
                	if (uri.equals(SHUTDOWN_COMMAND)) {
                		break;
                	}
                }
                // 创建 Response 对象
                Response response = new Response(output);
                response.setRequest(request);
                response.sendStaticResource();   
                // 关闭 socket 对象
                socket.close();     
            } catch (Exception e) {
                e.printStackTrace();
                continue;
            }
        }
    }
}