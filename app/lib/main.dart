import 'package:flutter/material.dart';

void main() => runApp(VitaBandApp());

class VitaBandApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'VitaBand Companion',
      home: HomePage(),
    );
  }
}

class HomePage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text('VitaBand Companion')),
      body: Center(
        child: Padding(
          padding: const EdgeInsets.all(16.0),
          child: Column(mainAxisSize: MainAxisSize.min, children: [
            Text('Welcome to VitaBand', style: TextStyle(fontSize: 20)),
            SizedBox(height:12),
            Text('This is a scaffold app. Add BLE scanning and connection to receive vitals.'),
            SizedBox(height:20),
            ElevatedButton(onPressed: (){
              // placeholder action
              ScaffoldMessenger.of(context).showSnackBar(SnackBar(content: Text('Implement BLE scanning')));
            }, child: Text('Scan for device'))
          ]),
        ),
      ),
    );
  }
}
