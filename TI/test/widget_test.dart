import 'package:flutter_test/flutter_test.dart';

import 'package:distribuidora_andina/main.dart';

void main() {
  testWidgets('muestra las tres pestanas principales', (tester) async {
    await tester.pumpWidget(const DistribuidoraApp());

    expect(find.text('Inicio'), findsOneWidget);
    expect(find.text('Ruta'), findsOneWidget);
    expect(find.text('Pedidos'), findsOneWidget);
    expect(find.text('Distribuidora Andina'), findsOneWidget);
  });

  testWidgets('permite abrir la pestana pedidos', (tester) async {
    await tester.pumpWidget(const DistribuidoraApp());

    await tester.tap(find.text('Pedidos'));
    await tester.pump();

    expect(find.text('Aceite Primor 1L'), findsOneWidget);
    expect(find.text('Registrar'), findsOneWidget);
  });
}
