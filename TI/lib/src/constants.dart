import 'package:flutter/material.dart';

const blueSlate = Color(0xFF4F5D75);
const seaGreen = Color(0xFF00916E);
const silver = Color(0xFFBFC0C0);
const nightBordeaux = Color(0xFF45050C);
const surface = Color(0xFFF8F9F9);

const titleStyle = TextStyle(
  color: Color(0xFF1A1C1C),
  fontSize: 16,
  fontWeight: FontWeight.w700,
);

final bodyStyle = TextStyle(
  color: Colors.black.withValues(alpha: 0.62),
  fontSize: 14,
  height: 1.35,
);

const priceStyle = TextStyle(
  color: blueSlate,
  fontSize: 16,
  fontWeight: FontWeight.w800,
);

String money(double value) => 'S/ ${value.toStringAsFixed(2)}';

void showMessage(BuildContext context, String message) {
  ScaffoldMessenger.of(context).showSnackBar(
    SnackBar(
      content: Text(message),
      backgroundColor: blueSlate,
      behavior: SnackBarBehavior.floating,
    ),
  );
}
