clear;
close all;
clc;

% Laboratorio 5 - Ejercicio 8
% Enunciado:
% Disene una espira cuadrada y encuentre el campo y potencial electrico con
% referencia al ejercicio 1, donde cada lado esta conformado por 20 cargas.
% Considere solo cargas positivas o negativas.
%
% Implementacion:
% Se generan graficas separadas para campo electrico y potencial electrico.

k = 1;
L = 1;
N = 20;

xaCampo = -1.2:0.12:1.2;
yaCampo = -1.2:0.12:1.2;
[xCampo, yCampo] = meshgrid(xaCampo, yaCampo);

xaPotencial = -2.1:0.12:2;
yaPotencial = -2.1:0.12:2;
[xPotencial, yPotencial] = meshgrid(xaPotencial, yaPotencial);

[xc, yc] = crearEspiraCuadrada(L, N);

signos = [1, -1];
titulos = {
    'Cargas positivas'
    'Cargas negativas'
};

figure('Name', 'L5 Ejercicio 8 - Campo electrico');

for caso = 1:numel(signos)
    q = signos(caso) * ones(1, numel(xc));
    [Ex, Ey] = campoElectrico(xCampo, yCampo, xc, yc, q, k);

    subplot(1, 2, caso);
    quiver(xCampo, yCampo, Ex, Ey, 0.6);
    hold on;
    dibujarCargas(xc, yc, q, 4);
    dibujarEspira(L);
    axis equal;
    axis([-1.2 1.2 -1.2 1.2]);
    grid on;
    xlabel('x');
    ylabel('y');
    title(['Campo - ', titulos{caso}]);
    hold off;
end

figure('Name', 'L5 Ejercicio 8 - Potencial electrico');

for caso = 1:numel(signos)
    q = signos(caso) * ones(1, numel(xc));
    V = potencialElectrico(xPotencial, yPotencial, xc, yc, q, k);

    subplot(1, 2, caso);
    niveles = nivelesContorno(V, 50);
    contour(xPotencial, yPotencial, V, niveles);
    colorbar;
    hold on;
    dibujarCargas(xc, yc, q, 4);
    dibujarEspira(L);
    axis equal;
    axis([-1.7 1.7 -1.7 1.7]);
    grid on;
    xlabel('x');
    ylabel('y');
    title(['Potencial - ', titulos{caso}]);
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
