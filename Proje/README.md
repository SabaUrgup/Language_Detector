[TR]
# Proje ve Kod Detayları

>**Problem**: Kullanıcı tarafından girilen bir metnin İngilizce dilinde mi yoksa Almanca dilinde mi yazıldığının otomatik olarak belirlenmesidir.

> **Açıklama:**
   > - N-gram: n adet elemandan oluşan ardışık dizidir. 
   > - N=2 olduğu durumda bigram olarak isimlendirilmektedir.
   > - N=3 olduğu durumda trigram olarak isimlendirilmektedir.

>**Görev:** 
>   - [x] Kullanıcıdan bir metin alınacaktır. 
>   - [x] Kullanıcıdan alınan metin üzerinde önceden belirlenmiş olan bigram ve trigramların frekansları hesaplanacaktır.
>          _(frekans hesaplaması: her bir bigramın ve her bir trigramın bu metinde yüzde kaç kez geçtiğinin bulunması)_
>   - [x] Bu hesaplamalar sonucunda elde ettiğiniz frekans matrisi ile projeye dahil edilmiş taslak kod içerisinde verilen frekans matrisi ile karşılaştırılacaktır.
>          _(bu matriste İngilizce ve Almanca dillerinin frekans değerleri yer almaktadır)_
>   - [x] İngilizce ve Almanca dillerinin her birinin frekansları ile elde edilen frekans matrisi arasında ayrı ayrı uzaklık hesabı yapılacaktır.
>          _(öklid uzaklığını kullanabilir)_
>   - [x] Hangi dil ile daha küçük uzaklık değeri elde edildiyse, metnin yazıldığı dil olarak o dil tahmin edilecektir.

---

[EN]
# Details

>**Problem**: It is the automatic determination of whether a text entered by the user is written in English or German.

>**Description:**
   > - N-gram: It is a sequential array consisting of n elements. 
   > - It is called bigram when N=2.
   > - It is called trigram when N=3.

>**Mission:**
> - [x] A text will be retrieved from the user.
> - [x] Frequencies of predetermined bigrams and trigrams will be calculated on the text received from the user.
>       _(frequency calculation: how many times each bigram and each trigram occurs in this text)_
> - [x] The frequency matrix you get as a result of these calculations will be compared with the frequency matrix given in the draft code included in the project.
>       _(frequency values of English and German languages are included in this matrix)_
> - [x] The distance between the frequencies of each of the English and German languages and the obtained frequency matrix will be calculated separately.
>       _(can use euclidean distance)_
> - [x] Whichever language has the smaller distance value, that language will be guessed as the language in which the text is written.
