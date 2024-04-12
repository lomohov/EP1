#include <bits/stdc++.h>

using namespace std;
#define int intmax_t
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define fst first
#define snd second
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<pii>;

unordered_map<char, string> hexToBin = {
    {'0', "0000"},
    {'1', "0001"},
    {'2', "0010"},
    {'3', "0011"},
    {'4', "0100"},
    {'5', "0101"},
    {'6', "0110"},
    {'7', "0111"},
    {'8', "1000"},
    {'9', "1001"},
    {'A', "1010"},
    {'B', "1011"},
    {'C', "1100"},
    {'D', "1101"},
    {'E', "1110"},
    {'F', "1111"},
};

auto convertToBinary(const string&image) -> string {
    string res;
    for (const auto item: image) {
        res.append(hexToBin[item]);
    }
    return res;
}

void addImagePart(stringstream&image, stringstream&result) {
    char sym;
    image >> sym;
    result << sym;
    if (sym == '1') {
        image >> sym;
        result << sym;
        return;
    }
    addImagePart(image, result);
    addImagePart(image, result);
    addImagePart(image, result);
    addImagePart(image, result);
}

void andImages(stringstream&image1, stringstream&image2, stringstream&result) {
    char sym1, sym2;
    image1 >> sym1;
    image2 >> sym2;
    if (sym1 == sym2) {
        result << sym1;
        if (sym1 == '0') {
            andImages(image1, image2, result);
            andImages(image1, image2, result);
            andImages(image1, image2, result);
            andImages(image1, image2, result);
        }
        else {
            image1 >> sym1;
            image2 >> sym2;
            result << static_cast<char>('0' + static_cast<int>(sym1 == '1' && sym2 == '1'));
        }
        return;
    }
    if (sym1 == '1') {
        image1 >> sym1;
        if (sym1 == '0') {
            result << "10";
            stringstream trashbin;
            addImagePart(image2, trashbin);
            addImagePart(image2, trashbin);
            addImagePart(image2, trashbin);
            addImagePart(image2, trashbin);
            return;
        }
        result << '0';
        addImagePart(image2, result);
        addImagePart(image2, result);
        addImagePart(image2, result);
        addImagePart(image2, result);
    }
    else {
        image2 >> sym2;
        if (sym2 == '0') {
            result << "10";
            stringstream trashbin;
            addImagePart(image1, trashbin);
            addImagePart(image1, trashbin);
            addImagePart(image1, trashbin);
            addImagePart(image1, trashbin);
            return;
        }
        result << '0';
        addImagePart(image1, result);
        addImagePart(image1, result);
        addImagePart(image1, result);
        addImagePart(image1, result);
    }
}

auto collapse(stringstream&in) -> string {
    char c;
    in >> c;
    if (c == '1') {
        in >> c;
        return string{"1"} + c;
    }
    vector<string> a(4);
    generate(all(a), [&in] { return collapse(in); });

    if (a[0][0] == '1' && all_of(all(a), [&a](const auto&e) { return a[0] == e; })) {
        return a[0];
    }
    return accumulate(all(a), string{"0"});
}

void solve() {
    int imageCounter = 1;
    while (true) {
        string image1, image2;
        cin >> image1 >> image2;
        if (image1 == "0" && image2 == "0") break;
        auto binImage1 = convertToBinary(image1);
        auto binImage2 = convertToBinary(image2);
        binImage1 = binImage1.substr(binImage1.find('1') + 1);
        binImage2 = binImage2.substr(binImage2.find('1') + 1);

        stringstream im1(binImage1), im2(binImage2), result;
        andImages(im1, im2, result);

        auto collapsedResult = collapse(result);

        string addOne = "1" + collapsedResult;
        string quad = string((4 - addOne.length() % 4) % 4, '0') + addOne;

        stringstream hexStream;
        for (size_t i = 0; i < quad.length(); i += 4) {
            hexStream << uppercase << hex << stoi(quad.substr(i, 4), nullptr, 2);
        }

        cout << "Image " << imageCounter++ << ":\n";
        cout << hexStream.str() << "\n\n";
    }
}

auto main() -> signed {
    istream::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
