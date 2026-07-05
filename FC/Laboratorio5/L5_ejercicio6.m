clear;
close all;
clc;

% Laboratorio 5 - Ejercicio 6
% Enunciado:
% Disene una espira cuadrada del potencial electrico con referencia al
% ejercicio 1, donde cada lado esta conformado por 4 cargas.
% (a) Todas las cargas iguales positivas.
% (b) Todas las cargas iguales negativas.
% (c) Cargas intercaladas con positivos y negativos.
%
% Implementacion:
% Se distribuyen cargas en los cuatro lados y se calcula el potencial V.

k = 1;
L = 1;
N = 4;

xa = -2.1:0.12:2;
ya = -2.1:0.12:2;
[x, y] = meshgrid(xa, ya);

[xc, yc] = crearEspiraCuadrada(L, N);

qIntercaladas = ones(1, numel(xc));
qIntercaladas(2:2:end) = -1;

casos = [
    ones(1, numel(xc));
   -ones(1, numel(xc));
    qIntercaladas
];

titulos = {
    '(a) Todas las cargas positivas'
    '(b) Todas las cargas negativas'
    '(c) Cargas intercaladas'
};

figure('Name', 'L5 Ejercicio 6 - Potencial electrico en espira cuadrada');

for caso = 1:size(casos, 1)
    q = casos(caso, :);
    V = potencialElectrico(x, y, xc, yc, q, k);

    subplot(1, 3, caso);
    niveles = nivelesContorno(V, 50);
    contour(x, y, V, niveles);
    colorbar;
    hold on;
    dibujarCargas(xc, yc, q, 6);
    dibujarEspira(L);
    axis equal;
    axis([-1.7 1.7 -1.7 1.7]);
    grid on;
    xlabel('x');
    ylabel('y');
    title(titulos{caso});
    hold off;
end

function [xc, yc] = crearEspiraCuadrada(L, N)
    t = linspace(-L / 2, L / 2, N);
    xc = [];
    yc = [];

    for i = 1:N
        xc = [xc, t(i),  L / 2, -t(i), -L / 2];
        yc = [yc, -L / 2, t(i),  L / 2, -t(i)];
    end
end

function V = potencialElectrico(x, y, xc, yc, q, k)
    V = zeros(size(x));

    for i = 1:numel(q)
        r = sqrt((x - xc(i)).^2 + (y - yc(i)).^2 + eps);
        V = V + k * q(i) ./ r;
    end
end

function niveles = nivelesContorno(V, cantidad)
    valores = V(isfinite(V));
    niveles = linspace(min(valores), max(valores), cantidad);
end

function dibujarEspira(L)
    a = L / 2;
    plot([-a a a -a -a], [-a -a a a -a], 'k:');
end

function dibujarCargas(xc, yc, q, markerSize)
    positivas = q > 0;
    negativas = q < 0;

    plot(xc(positivas), yc(positivas), 'ro', 'MarkerFaceColor', 'r', 'MarkerSize', markerSize);
    plot(xc(negativas), yc(negativas), 'bo', 'MarkerFaceColor', 'b', 'MarkerSize', markerSize);
end
