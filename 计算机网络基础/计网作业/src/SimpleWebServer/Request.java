package SimpleWebServer;

import java.io.IOException;
import java.io.InputStream;

public class Request {

	private InputStream inputStream;

	private String uri;

	// 从InputStream中读取request信息并打印，并从request中获取uri值
	public void parse() {
		// 创建字符串缓冲
		StringBuffer request = new StringBuffer(2048);
		//
		int i;
		// 创建字节数组
		byte[] buffer = new byte[2048];
		try {
			// 读取数据填充到字节数组 buffer，并返回读取的字节数 public int read(byte[] r)
			i = inputStream.read(buffer);
		} catch (IOException e) {
			e.printStackTrace();
			i = -1;
		}
		// i 为读取的字节数，
		for (int j = 0; j < i; j++) {
			// 将字节数组转换成相应的字符串，即为 request
			request.append((char) buffer[j]);
		}
		// 打印出 request的信息
		System.out.print(request.toString());
		// 从 request 中获取 uri 的值
		uri = parseUri(request.toString());
	}

	// 根据 HTTP 请求报文的内容获取相应的 uri
	// uri 位于第一行的方法之后 与方法间隔了一个空格 eg. GET /somedir/page.html HTTP/1.1
	// 可以采用通过求子串的方法，根据uri前后的两个空格来提取 request 中的 uri
	private String parseUri(String requestString) {
		// 声明索引
		int index1, index2;
		index1 = requestString.indexOf(' ');
		if (index1 != -1) {
			index2 = requestString.indexOf(' ', index1 + 1);
			if (index2 > index1)
				return requestString.substring(index1 + 1, index2);
		}
		return null;
	}

	public void setUri(String uri) {
		this.uri = uri;
	}

	public String getUri() {
		return uri;
	}

	public Request(InputStream inputStream) {
		this.inputStream = inputStream;
	}
}
