clear;
close all;
clc;

% Laboratorio 5 - Ejercicio 5
% Enunciado:
% Disene una espira cuadrada del campo electrico con referencia al
% ejercicio 1, donde cada lado esta conformado por 4 cargas.
% (a) Todas las cargas iguales positivas.
% (b) Todas las cargas iguales negativas.
% (c) Cargas intercaladas con positivos y negativos.
%
% Implementacion:
% Se distribuyen cargas en los cuatro lados y se calculan Ex y Ey.

k = 1;
L = 1;
N = 4;

xa = -2:0.2:2;
ya = -2:0.2:2;
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

figure('Name', 'L5 Ejercicio 5 - Campo electrico en espira cuadrada');

for caso = 1:size(casos, 1)
    q = casos(caso, :);
    [Ex, Ey] = campoElectrico(x, y, xc, yc, q, k);

    subplot(1, 3, caso);
    quiver(x, y, Ex, Ey, 0.6);
    hold on;
    dibujarCargas(xc, yc, q, 6);
    dibujarEspira(L);
    axis equal;
    axis([-1.2 1.2 -1.2 1.2]);
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

function [Ex, Ey] = campoElectrico(x, y, xc, yc, q, k)
    Ex = zeros(size(x));
    Ey = zeros(size(y));

    for i = 1:numel(q)
        dx = x - xc(i);
        dy = y - yc(i);
        r2 = dx.^2 + dy.^2;
        r3 = r2 .* sqrt(r2) + eps;

        Ex = Ex + k * q(i) .* dx ./ r3;
        Ey = Ey + k * q(i) .* dy ./ r3;
    end

    Ex(~isfinite(Ex)) = 0;
    Ey(~isfinite(Ey)) = 0;
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
