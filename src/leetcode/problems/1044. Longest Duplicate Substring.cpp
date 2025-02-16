#include <bits/stdc++.h>

using namespace std;

static const int P = 31;
static const int M = 1e9 + 9;

class Solution {
    public:
        string longestDupSubstring(string s) {
            int n = s.size();
            vector<long long> hash;
            vector<long long> pow;
            hash.assign(n + 1, 0);
            pow.assign(n + 1, 1);

            for (int k = 0; k < n; ++k){
                hash[k+1] = (hash[k] + (s[k] - 'a' + 1) * pow[k]) % M;
                pow[k+1] = (pow[k] * P) % M;
            }

            string target = "";

            int min_l = 1, max_l = n - 1;
            while (min_l <= max_l){
                int mid_l = (min_l + max_l) / 2;
                
                bool duplicate = false;
                unordered_map<long long, vector<int>> h2i;
                for (int i = 0; i < n - mid_l + 1; ++i){
                    int j = i + mid_l - 1;
                    long long hij = (hash[j + 1] + M - hash[i]) % M;
                    hij = hij * pow[n - i - 1] % M;
                    if (h2i.find(hij) != h2i.end()){
                        auto curr = s.substr(i, mid_l);
                        for (auto& index : h2i[hij]){
                            auto str = s.substr(index, mid_l);
                            if (str.compare(curr) == 0){
                                target = curr;
                                duplicate = true;
                                break;
                            }
                        }
                        if (duplicate)
                            break;
                    }
                    h2i[hij].push_back(i);
                }

                if (duplicate)
                    min_l = mid_l + 1;
                else
                    max_l = mid_l - 1;
            }
            return target;
        }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

int main(){
    Solution sol;
    string s = "qzyhifqvxqzjftmnrozudbqnwnovmjlrfpzcumagueeahlbkdpccwvlyggbbmluorefmddfqsxjncwiawmntgvklieagbosrwblqfeusxwcdhzauvrgjwdrdortzprzpotbtrfjafvzvjaaogzwrpaqytipkrgulfrxvsvybbevwebmmkmvaqdpmoihqbuyehxrewwwuinzkvcinxwijsrygswvbhlqvvejkbhzoekacvgrvkmwfkxcobeupjlxbsbsvuurkaacvdrzlxbeafvowsxisawxvoxoudjynnpsepyjppztunldfvehezknznvksrxdpjxskpatjapombnrrjvpaymietxkuuxjsioxinkuzsjdudmnwenonbxsyildtozmskrjkhebwqzcuqysoiakrdrlihjpxwcwpwajgmdoluoytldpgwpjaumfasvwuiqfvhlvbnpxjxffebnbhtdgxctsvgzbgjswyarawfauiehivqaidizgwasezqpvahhupdnzrjvqkovwkatzvdklnsoqmxsvvxelepndelokgnwnymyhicrzjwssnjoolffudjpozthldqkilznfxocizwvhlfgsfjhtugkmjqqarkvvzrmxijhlhfhubnuvtlotwvydfuwczluhyrswnhqgwlfjbjjcrwrxqwjqyjqnhmgadtzbnweqphvkmnuzobfyrmbsitbhpnjeczmvfgbffixuihzbznkaxaxdkpxqokhmjpfoscvkmvocmdskuhvjjuzvvcfytjfaqshlmyeufdmbshqmkhbmzgxylvzafqiofazrpxpbvenirsbjqeamwucckyvdexihynrorzwybjmhtvbuiecpwxdernpxivcryawaujagxuyptynbaszvrumcqkipskasdjjqlltetdcafotqllogdbaodktkkmxnaomehrlrsnhxycbjpwokldvtrxgcrbibpqxomjtlqmhdhueegtuperalubyjuvypnybazizbniogoizhftvvviuhllqynloygtnesqsvjmysdlnhusiqsbybkfiaampozicopqyubyzujxpwycuqphothkihdaffeguybshepkzlwshebpasdrsokntokwgmvglewkauzhbepbetvvlewiqonszdnnczwdlsumqjtcenzejrbfxnhcrbindztbvpdjcrwpppdhccpljjkcnfpkqwinnmlwlvcorgnblovryqkytxargedbyxmbybamiuxkraivtvmzyszuzzjdcfxkaqazaugciqflfsnncokdiuytzaelbclipmmeajsefgdwjrttxrokerobjgkmbgrwppojqgecpuyljjjiogqmyakjoyqykphuhqgomhgufrkuxaizanaclswlmmorpclkxcclaviqaqiauoxfjjznanbuhxpdoxuvfouprwtqfkzjlgwiaamqohsjpzhltvendnoimuwaibnzssetsslsrsejestzoizrjpvrctrxjgsikdpigphzaeuzzjqbhlsxzvghnfdkusztgbffyutmoirsfnclhngedhaamxveqyuryrhbvglfybtcjoesruiptbcgfsrueuwuldibxnfptopsihvqwzmuzubbxvxjwpfiearhsulqspckmrbioaqgdojotwbbbxhihjssdnlbinwavkkjhnmbdawbstycmfmbkiilkegersyzuaqtphgtshlesebaovmmnislipujlwkruxyecsvwbapcegwumnardxhkamimimzjjvmqujuqhwrbbyoebpaihkykfrlvnzqfndkbcxyugsuygdujavwasdjudnjueibtuflzzftehmrpkhuxdgkjffuoetfbmqlftgozscaelrlewzqpbfholvqruxzuvefewqeqjplwpkaydqmjomjbjqqepnepmzfqzwpwysquulnflrmoiaxcqmviakxjmyhujmrgpjbkbzevyebvshxndrcboadkjnqbyvdwnblkohqaytwpszoyfknigeqfnvjvmsefdwhaeljrfzemwoeyorrhyfaqwuwhdglifxcqumzeuavzaqgcjrkliuqgxyadanbdnuvpczxoaoxnxqqxhkruilmymaotxdntvezuxobgnhsmfgnschyoqmzhgomnpjcjptpdsrxgitmruufwposmzdxdilmvnxjhewjvgnuftvrqqoctrhtrpsjfjzbgzrjydrwjqgivavlexosfgajzuctseqnnnqdjljbxetojiyhuxulcpimgbswllngoiobkbrgmaxjvpcpfkvdcecmfhcvgwnzrufcmbmtrqlarwgfvypwmycqyqnqinrehbtukntpowannukmrxjocnvxoejvapoifopuojqkpwkdblbizyimmtwbyymazbtirnmycejseigroyilwgcrzgfwmfempbpdabkzkndlxuxzlymucjvsledhxsgezuclfiflkvzwklqicteklwjkstycvtxlbywqupvjozfjewahfyewpnxuajrsntlzcqssgdvkjaldswdphppjacuixjhlozpfquwdtagyzwjzqmflsnjacbtyqrvlkcbjoofuliibtvlqxjwehxmqmwzvvpibxwpwiujbuotbpcddrbgjvrsbocklkadsjlvajlyksnbkosmsetipgsmmdbwtfwrfzvwsffwwwxnbzwebglwveirgakvbukzchzyezvimfyitydeezmruedfgkyvjhqtoehcufjpglptrqlvybmgowqszxbtjnzccujhqtdchjafsnousmzfmfrvnimprcanprnkqcdlxwotpixhvyvixejxwjxeqxryxkdgdmjxuameonlfwnqgwbmozdpmbkucdzybdddsbvgubfdyczulxrnoexvphcmllsdelzqiumyfdydlodkqdvzwwbhienvmuppuzmdvaheydelpmohawyuphnjezqofwqumlcvstzbqfmwunecbbwuopqbojiubxjroaksgiyndorwqgxikdtaluovrcztauunrhefeacbqqrmytdmhgfwkhipuomzovkdlcfehbgtvkkpoivmphibrgqwprbvpihfjdlwufuygehwyzecervyvcjwelstvrhanhopgmxpwooocczhzxzopsubbtolnhgmvbxoodrldugfpppgzreraddkjogvkcmzdwejlwecznstjlwyuccmxdachmougvtxqurjxwhyidjpsriaeepcijyhixipgwvkinhwsqnaxkifsltgcooluvqyjtvbtzjqqddizngtofaqwhlmhwsteqmxwmmivxetbmqquheyfzjpwjzhmmrljisvfmanmlvyweqebaitfgekligdrckntkhsrkfcqqmqvxffdcgnqswlqbfrujislqqoalwhakechbrqodfyccquslsimrauzmuiqajeidzbdhacpengtbsqnkjrrnmculbznjxruzmjxvytzjpqjrurndhyxwegkjvazhrzibeymfgsmmmmtusbrjittiqmrpzcdtancxkfhlofrltvmdzabzqvildqqtdxzztgqrtzndmgjaznjkihbotpwhaqabbllcufkmzbkkqwexikvmvykntyuemdcptkugjzlvwzluipurwbvmymfvbaamqbcithdpsinizebkrcirdnuzzqooqsisyaibmdzsbsagjlqlepbddwopuycrnosmmrsdhsuxvuillbqtfkqettcvfdckhfromtemionkddaimrrgqseusnvhasnuazmpjvxmbjfvwkufbkgqddalpjmleabxenklrudejfklzljqthwpvjrgsmgtmkdekmqqbreajorzhovtokggmpkraxfxwyjidnmmrscjugeytjifpujqabhggsslblgbrutmudwvzboonwvmgooqqdnfmumigtvbjpofgqhyzqrabypwgrpspomwjlmutpcdzvbfcpeeyprktxbtskxtxiyopqqwcvcaahfbklygkwdrrnuqjwujjggflkewnbmmhmaypeukwznuyotqsmgxeswfxtueaqhtbywmuqdhzfbjbshjfuybkgmpozbujwqfcrdzvibrfzkbhfyjgbqwboqxcuxaylqzvwaxoftbuwexhgeipabnpdierfxqakokuynogkwkzgtijcldmohmrgojijxgjmvgbroisvvzluaknwvemcjetvccctpsgcswpxdcqwzhgygjidormnuvngtlayhddoulhpjqjhnzwkgqbzmyktsodervfgtsdgcwlpslnrjispdrvhefdwrypkcflwalgibowrsarrdchumoozmxwcyzoyiglimmpaiamjghhmkooodoxejmiyupxvbzpqrlmwshansnnldgdqqqjpovjctcjsfakxjtaxvtyeivyeqswnaetyugdwtipkorimmjcdhvcwaaxjbfhmjvvzzalvrfsqtcblwodifqaowgeyrpjlqfjvsiwiolxktihplymyqnyhshahzsyxuslcicjtamqyajmwcdwnlhctlckhrjqnhrvgsgwdcsrlzgittybcghdhvqwgavpkzgscdgcpbhmimcjcmtxauqrnsjthsgubdepkalwoijbjiujyorolrcbyjurgnszjfcaqijljyefddnhkogbedhvvfycjgcbfiepincgckvsabhltdndlhzqbhfsexaikprzmenteuvzvrgsfuppovqttdunncecggkwrhlqkogapefamibecsjampvqcsfuyybuyugbyohwyizikcypqqqvgncvkvrpaypfwgzxyjlnhhspgrihratkqydgvcikatswrlrouvxrmerolrclryccaxyextwmvnjjmzhblrduevfhidyymkwsvcxcvfebljpeasxovpsrggyobprgyskppyqijwbrrclbjhthteejbeiwufuxnralcfounqoymilqjshxzjnldaygssmgwhyhbqfburgqmvaiislavovqgqfftdwuyrsryzxkcvavxigaslnxcldjlshzziactsxpdrxdkmpsmbqvflqsqgvafadhrfczuctuogtcpbqxgbhfmgzbiilzjvzrdxocgubhbyapkcrogxxetcixinxdfizxmqxhvrjxiuostknxggnzvxizantzrbkqjopjbuijnxgkwwvoxatisuebrihofhxrnkawihsdtyqzpnxiuwrzwkqhpxivksermwuvylanotmwugimycbhsdnbtgtdfltzmlrqycqrqynaktrwllwfiyfduwgrmjocovkgxaknfsgtrgbbcobqgrapmsocjgzjiivhxpekxchmaesbcwkrchfafsyrepjurybslsmjutzjqzugytefrajxohpvtuzlyvgvynlrxmvjqejfqkjifrddkggydmwbylhxbspgmtksqgrsfrmjfxruayuptdpkwgupxqnwavwizhozbqlzvkajybdrwffokxobplphjcrkcgmkbcjxnafbbfwnowsfmepczhwvydrmkqmvsuxfiawdmhlyzxsseqvwncgubzxrdjhlyacvwmexumujfreeffhkqgxxheurudgtfpblgwtbbgshyqybjzpjncqpdhurjvgvvlmukaqwnpiflfmeiuwtqbaidvuhgceuetnrafuuaohnifvuzrxzbytqymgfbzfstvrljrogqoizwtmmxxrinbayohbjbhyyajpawstcqbifblkraduhnldtcusrpcyncoqpkrizsrhlpndzwsttcbhhwkynffmlsdjseiswoogfftxvuwadfjkuowpazberekjkvpblwlauqxcnfkoctcjraauxlkwglaoyzfsfsjmhqkjejqthhxcikeyexbwzbpkbeokjbvwbaiddkhgeleguombrubdazlkwgzuieuazbgjzbwvzktjpfpetnvggparepplkitwwjfyyrkowmdvkbstryjeuihtceoojtpzrfozpkndtdfvzynxnqgxnkqlhvctjbenatmjplpiidhuwnmqhcypuzyejhqkzcdifzcwkkjqmioiugxqovwawtptphkqahoimszxdwiledlhktwikiviageynbmsslqrbbqrwanfkoonsurnwonxovhjltpnxeykymuamqghwuawmszbzxmnjskrbmoemdfkhacomtydxuimrfurypacddqyvjpwazzkfynqcvrjbglsqnxmxypzzgcnjiynvzyzdvclgorbsymsxsumzmyxlsmsagkrkkpuaixodkwghrzvtufyqiwcnyexiykaldlwszlarkpcwqgjdckqtolhwsaihlajvhnwelioirzicdsryicyknlodzfgnrexjxrzfhhtlfvuttccbavqsfwkptfrqbofvvfuyloaeyywawynkuhdprnbgslccvnlmelpzxzsyhnioezpzhychfxggxydcdoxrmylqqfhsuzsknwtjivnotqcutsbmkgenaomusnabqfvzncjjobczkiokayolaipefuwspsxitnkazzzaismvqlipllwpltyfiksmecajqpobpcipmyzzlwfpgpooxzjspywjsthhosuhmlgfowdynordgrxirfelicizbqekbvzsmffjtonphoznqoidhfomhnvyavlhqnapuherhxqlzyeyswnfdrixkagkhbmovprtrqiojnyrbaozzenamujynxwymymqcsqptyypptoqjutirxoyychearrbtlkswiqwkrddwiuchjlfvattexashrkicdrujeganeknpgrteknfoqfacblczykohcwhgmhscorpchemulmmrpkhmroztajfsjhtoukmkfaxwadlidhfwvxesvdvsstsfouejqphkxrhbsqaybyiwdabnugehfnwyocddkmacaqbzyvaqcgbuiqujqingzxwlrhpzmiwxqgyakmsjatblzmykxfgswxssqdetnxmbwmhfmiygcwoehbbcjurcpbmnkrmmqhqnnbgxngrsrcyqbcgwmfxohgpkjolonzpiyxpzzxkzbskimbaxynlkhnlhszrwkzikoemtelclfblrzmczakkjsruknwgkfhenjbqqptglabctxbaeuuolumwcoewpaxoyugwzcwgrfmfzpmnsudtodrcvvqzxbripppclpmuanltyzlbxqrlbpglddhmybqqbztzfhassmwmughewypxoqyigkbvrslppvcljljweghsoavviljpxyuizsvqmpyajtucqywrdfgzwsfqujpcqmyjzllgnwjbeaorebdtjrzyryfvtxzabiihhyaommjtregkzbkqnpcrombipdsaksauwkmknnddoeusjohvhybubgicjrfdtitjwzfpzozdjfzbtzcvbvpsrknbrlbmgkgcsjeuuncscektrnyuidrnhmjsukjbbjvyqrkhsktkxlqomrefacmdvfkikdpjewhcssucebcjvmnbgohufhmzfoitjwcwmdbqemzhsdyzlkhwgpwaajfcctlcdotlbmwwygwycailktbxaskhveletgjfknimiyxzjotndkoveohzfbrvmgtuavsozlpqjqtvtoneuwgyfcwriijmvegbrzqstefbjxilfdcjzstkcqdbydzoqrlarmdiaqwwfeoppsjexlfclsxtcveqapjtgaykcexjrwkrtapcdoauxfstrqqgwkoabmcmbkxxtiodchrhdcpynbycqeokfeqemohevcndlflitkyldnfxicszkcqpjcznsglprmdqdiatlfumewlvgcepulxteszpiijbuwajwsseesrafapnngexwfnuvefkaiggkhisvfykbaekdtwvypuknliczohuqntlxtfxkfwuqakbeeskgwxnchwglehactftlanjmwmzkmcesvwgnlvwodtlijskdpcdpuqzrfqdsdwwfruefbomruafbrcpojibzvdeujybrbkleoqfmnbpuxwpddlyxaqqlglsphkbgdqdhxecfzaxghwxncbulydniummqycuuejbzesrnxdkmtchkcoomzzolsdpxamsshmuyfrcvyxwzwayzuuyycboqhwaohfqckhwuactcpomwaaqubmgwsoskfkrztltimqfeatygijqgajgldzrwlemgxxgwjpxjlyukjxqjzgutwdquancxknjrepytcldsqahqpvchrgyoiqvmubivatvwwxpqmraxdhbojaccupwjvejpwgservfeiuerudjharlljayvdkoavmpbobrptjzuvqhndjspwmcwqjleejncbojnhiofinchxkqhtyfuzmttnlcfrvglztoezizqhzoabpgmimepacgjymuuuhdbitdcpmgrjfakgeigtmaqbiqktyarfphecrkxqahxcbkdfafvcfuufmyspsmmlokmmwgzkovaiewlossfcaqccfjqdnnmrldbbempkzlknpobuozmtbojtvzzjfosedmhmvshxhknoaulcpxyrawdbygocekxodantypuromnouxwjvnagndmphpwflabnjbkpowmunpfthxgzhoucncxtscz";

    cout << sol.longestDupSubstring(s);

    return 0;
}