# Offline Audio DSP Engine


## Opis Projektu

Autorski, zoptymalizowany silnik do offline'owego przetwarzania sygnałów audio (plików WAV) napisany całkowicie od zera w standardzie C++20. Projekt opiera się na architekturze obiektowej (OOP) i implementuje profesjonalne algorytmy cyfrowego przetwarzania sygnałów (DSP) bez użycia zewnętrznych bibliotek dźwiękowych. Silnik służy jako fundament do zaawansowanej manipulacji dynamiką, częstotliwością oraz czasem w plikach audio, demonstrując pełne zrozumienie matematyki i fizyki dźwięku.

## Architektura Silnika

Projekt oparty jest na polimorfizmie. Wszystkie efekty dziedziczą po bazowej klasie interfejsu `AudioEffect` i operują bezpośrednio na wektorach próbek audio zmiennoprzecinkowych (floating-point) za pomocą wirtualnej metody `process(std::vector<float>&)`. Pozwala to na proste łączenie modułów w dowolne kaskady przetwarzania.

### Zaimplementowane Moduły DSP:

* **GainEffect:** Liniowe sterowanie amplitudą sygnału bazujące na szybkiej iteracji po wektorze.
* **DistortionEffect (Hard Clipper):** Nieliniowe przesterowanie sygnału z bezwzględnym ograniczaniem (clippingiem) szczytów fali.
* **DelayEffect (Feedback Delay):** Modulacja w dziedzinie czasu z algorytmem wielokrotnego sprzężenia zwrotnego. Posiada elastyczny bufor dynamicznie dopasowujący indeksy pamięci do zadeklarowanej częstotliwości próbkowania (Sample Rate).
* **IIR Filters (Low-Pass):** Cyfrowe filtry o nieskończonej odpowiedzi impulsowej (Infinite Impulse Response) oparte na równaniach różnicowych z niezależną pamięcią stanu dla każdego z kanałów stereo.
* **CompressorEffect:** Zaawansowany procesor dynamiki (Peak Detection). Wykorzystuje konwersję do domeny logarytmicznej (dB), matematykę redukcji zysku (Threshold, Ratio, Overshoot) oraz wygładzanie zmiany głośności (Attack / Release) za pomocą autorskiego filtra IIR chroniącego sygnał przed zniekształceniami fazowymi i cyfrowymi trzaskami.
* **MultibandCompressor:** Potężny, kaskadowy układ kompresji wielopasmowej. Wykorzystuje inżynieryjny system zwrotnic (Crossover) oparty na filtrach komplementarnych (odjęcie przetworzonego sygnału Low-Pass od oryginału w celu bezstratnego uzyskania High-Pass). Pozwala to na równoległe przetwarzanie dynamiki w wyizolowanych pasmach częstotliwości i ich bezpieczne sumowanie.
* **Korektor Parametryczny (Equalizer):** Kształtowanie widma częstotliwościowego w oparciu o filtry pasmowe.

## Obsługa Wejścia/Wyjścia (I/O)

* **Przetwarzanie Offline:** Wbudowana klasa `Riff` odpowiedzialna za parsowanie nagłówków plików `.wav`. System ładuje surowe dane PCM, tłumaczy je na znormalizowany standard zmiennoprzecinkowy (zakres od -1.0 do 1.0), aplikuje zdefiniowany łańcuch efektów, a następnie renderuje i zapisuje gotowy plik wyjściowy, zachowując prawidłowy przeplot (interleaving) dla kanałów stereo.

## Wymagania i Budowanie

* **Standard języka:** C++20
* **Zależności:** Brak. Projekt korzysta wyłącznie ze Standardowej Biblioteki Szablonów (STL: `<vector>`, `<cmath>`, `<algorithm>` itp.).
* **Format wspierany:** Bezstratne pliki WAV (Stereo).

---

Masz wszystko domknięte. Dobra robota dzisiaj, odpoczywaj! Zamykamy sesję?
