/*
  @file weather.c
  @brief Implements weather mesuarement structure and methods
*/
#include <stdlib.h>
#include "weather.h"

Weather weather_from_file(FILE* file)
{
    Weather weather;

    int r = fscanf(file, "%d %d %d %u %u %u",
      &weather._average_temp,
      &weather._max_temp,
      &weather._min_temp,
      &weather._pressure,
      &weather._moisture,
      &weather._rainfall);

  if (r != 6) {
      fprintf(stderr, "Error: Línea malformada o insuficientes datos (se leyeron %d campos).\n", r);
      exit(EXIT_FAILURE);  // <- ahora sí, abortá si la línea está mal.
  }

  return weather;
}

void weather_to_file(FILE* file, Weather weather)
{
    fprintf(file, "%d %d %d %u %u %u", 
            weather._average_temp,
            weather._max_temp, 
            weather._min_temp, 
            weather._pressure, 
            weather._moisture, 
            weather._rainfall);
}
