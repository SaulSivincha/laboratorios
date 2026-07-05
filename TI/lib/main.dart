import 'package:flutter/material.dart';
import 'src/constants.dart';
import 'src/data.dart';
import 'src/pages.dart';

void main() {
  runApp(const DistribuidoraApp());
}

class DistribuidoraApp extends StatelessWidget {
  const DistribuidoraApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Distribuidora Andina',
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: blueSlate),
        scaffoldBackgroundColor: surface,
        fontFamily: 'Roboto',
        useMaterial3: true,
      ),
      home: const HomeShell(),
    );
  }
}

class HomeShell extends StatefulWidget {
  const HomeShell({super.key});

  @override
  State<HomeShell> createState() => _HomeShellState();
}

class _HomeShellState extends State<HomeShell> {
  final pages = const [InicioPage(), RutaPage(), PedidosPage()];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: blueSlate,
        foregroundColor: Colors.white,
        title: const Text('Distribuidora Andina'),
        actions: [
          IconButton(
            tooltip: 'Sincronizar',
            onPressed: () => showMessage(context, 'Datos sincronizados'),
            icon: const Icon(Icons.sync),
          ),
        ],
      ),
      body: pages[selectedTab],
      bottomNavigationBar: NavigationBar(
        backgroundColor: Colors.white,
        indicatorColor: seaGreen.withValues(alpha: 0.14),
        selectedIndex: selectedTab,
        onDestinationSelected: (index) => setState(() => selectedTab = index),
        destinations: const [
          NavigationDestination(
              icon: Icon(Icons.home_outlined),
              selectedIcon: Icon(Icons.home),
              label: 'Inicio'),
          NavigationDestination(
              icon: Icon(Icons.route_outlined),
              selectedIcon: Icon(Icons.route),
              label: 'Ruta'),
          NavigationDestination(
              icon: Icon(Icons.receipt_long_outlined),
              selectedIcon: Icon(Icons.receipt_long),
              label: 'Pedidos'),
        ],
      ),
    );
  }
}
