package com.example.p2plive;

import android.os.Bundle;
import android.app.Activity;
import android.content.Intent;
import android.graphics.PixelFormat;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity {
	private boolean bifsdexist_ = false;
	private String strVideoPath_;
	private Button playbt_;
	private Button playWebbt_;
	public final static String PLAYURL = "com.example.player.PLAYURL";

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		LoadLibrary.load();
		TextView tv = new TextView(this);

		HttpServer httpThread = new HttpServer();
		httpThread.start();

		String words = "Hello, world! Tom ";
		tv.setText(words);
		setContentView(tv);

	}

	
	public static native int startHttpServer(int listenPort);

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.activity_main, menu);
		return true;
	}

}
