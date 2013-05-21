package com.example.p2plive;

public class HttpServer extends Thread {

	public void run() {	
		int result = MainActivity.startHttpServer(1234);
		System.out.println("After startHttpServer, result:" + result);
	}
}