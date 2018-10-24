#include<bits/stdc++.h>
#include <stdio.h>
using namespace std;
//int DiffString(string s)
//{   
//    int len,i,vowel_count=0,cons_count=0,consec_cons_count=0,hard=0,easy=0;
//    getline(cin,s);
//    len=s.length();
//    //cout<<s<<endl;
//    
//    for(i=0;(i<len);i++)
//    {   
//         s[i]=tolower(s[i]);
//        //cout<<"s[i]="<<s[i]<<" ";
//        if((s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')&&(s[i]!=' '))
//        {
//            vowel_count++;       //cout<<"vowel_count="<<vowel_count<<" ";
//            consec_cons_count=0; // cout<<"consec_cons_count="<<consec_cons_count<<" ";
//        }
//        else if(s[i]!=' ')
//        {
//            cons_count++;   //cout<<"cons_count="<<cons_count<<" ";
//            consec_cons_count++;// cout<<"consec_cons_count="<<consec_cons_count<<" ";
////                if(consec_cons_count==4)
////                {
////                    hard++;
////                    vowel_count=0,cons_count=0,consec_cons_count=0;
////                }
//        }
//        
//        if((s[i]==' ')||(i==len-1))
//        {
//          if(consec_cons_count==4)
//           {
//            hard++;   //cout<<"hard= "<<hard<<" ";
//            vowel_count=0,cons_count=0,consec_cons_count=0;
//            
//            
//           }
//           else if(cons_count>vowel_count)
//           {
//            hard++;  // cout<<"hard= "<<hard<<" ";
//            vowel_count=0,cons_count=0,consec_cons_count=0;
//            
//           }
//           else
//           {
//           easy++;  //cout<<"easy="<<easy<<" ";
//            vowel_count=0,cons_count=0,consec_cons_count=0;
//            
//           }
//         }      
//         //cout<<endl;    
//    }
//    
//    

//    return (5*hard+3*easy);
//}



int main()
{

    int t;
    cin>>t;
   cin.ignore();
    while(t--)
    {
        
        string s;
        getline(cin,s);
        int len,i,vowel_count=0,cons_count=0,consec_cons_count=0,hard=0,easy=0;
        len=s.length();

       // cout<<"\n";
        
        //cout<<DiffString(str)<<endl;
        
        for(i=0;(i<len);i++)
    {   
         s[i]=tolower(s[i]);
       // cout<<"s[i]="<<s[i]<<" ";
        if((s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')&&(s[i]!=' '))
        {
            vowel_count++;       //cout<<"vowel_count="<<vowel_count<<" ";
            consec_cons_count=0; // cout<<"consec_cons_count="<<consec_cons_count<<" ";
        }
        else if(s[i]!=' ')
        {
            cons_count++;   //cout<<"cons_count="<<cons_count<<" ";
            consec_cons_count++;// cout<<"consec_cons_count="<<consec_cons_count<<" ";
//                if(consec_cons_count==4)
//                {
//                    hard++;
//                    vowel_count=0,cons_count=0,consec_cons_count=0;
//                }
        }
        
        if((s[i]==' ')||(i==len-1))
        {
          if(consec_cons_count==4)
           {
            hard++;   //cout<<"hard= "<<hard<<" ";
            vowel_count=0,cons_count=0,consec_cons_count=0;
            
            
           }
           else if(cons_count>vowel_count)
           {
            hard++;  // cout<<"hard= "<<hard<<" ";
            vowel_count=0,cons_count=0,consec_cons_count=0;
            
           }
           else
           {
           easy++;  //cout<<"easy="<<easy<<" ";
            vowel_count=0,cons_count=0,consec_cons_count=0;
            
           }
         }      
         //cout<<endl;    
    }
        
        
        cout<<5*hard+3*easy<<endl;
        
        
    }
    return 0;
}




/*check for this

Input:
hmdpnroxffqgoknxgcrjuaygnvcfgkqoytgnlunqcexsqnrarjjnlkvygxg kwemtkchhpblvy oovoj awslstrsbhdanptatcjjfuhgawuvngeodyaxttswewwrotsjxeudafjaegxrncgseitxdmuhltbdpvonblq qcdwjbpyexrihnimbftobwrrtgfwsyxldbjmcbniyisgvduyioomogekpjhkkhvoifdmirxiasqvy vjdmvrsackmluwsrldyrqijqsjljhkvfucrqvn yxgktdgnrjojcyssrefenrctmelgbbxcaeovjulbfcmhchdvlkaccdvphjxklxmneclnyyrebeodoraccceefavpktaxr nvtymsaexbkmhyejcilgmrjljvfjtabhxuikoioolcdsbhcfrqmeivrtrafnahwxchjsrahdckwgtbllrxscvkvpmef lennlyjdyqjecikvjxkeydiuphndlsrwafmlgvrinbmrjypuwcbvhktxrhddcwcefoqlnktdniuwjmthpvfwgywa cdnafrfvkqlunoixlhibcpqaupiwnihplupspwqaqdxeticiqkjucawapfyfngvyenttlmvertimdmuvaeqe nevsfeimahspdmdpkhifrwkhtghxyleoschxgpmiyfbetgvfogmidwpwf weldsgicgqttcubdbxjwfaetjjqyjxygckmwqubylusprwsswfrehvxqiosrmraqempwjqvxn nfohanorrvqppygiquaqnegdbptwnjqcqhlquakoxbe cmvshxmuesahkvfyfxdxgoobqcqofwfikbbtcpp irotovuvtxuaolefnuvttbceffyhvqngiecyayvwwqwlcbsqxpmsqqyvvxftqvbcafbdfwaenwssbllbbx uovsmvyhnukpwrsawsaeiawbdimemmbhbwcqsbaixmaxetxembiwdfyinlocbpjeomukpusqhvooposerdbwicfxqwbromv btqtojkyfbpwridmnhlvltvcqyvfmslpmcjdovevwtvreygrirpwlmy lviaqvqfyaknwpjvlfpqhvkrobocpqfdopeflwmmwwavokubrkryjetaficuyjynyfunchabhbxvnu hhqjqvdqdnvbnfcdhhbuliumrxmonhnxphhidmciaxjpdlvk whghfvadiotserklbuqnwanulgbxcnuyxegdagikwefcvppwnhmkhbishlsjbokysqcuxnfwrnyqfppsydeggobpawbbnlbi fdc kalxbcgsryrwdxdrcstbtvofywkecmaoolpqpvjjuchbckuggphanvimusqyhqqwegnveygbbpcgcamipulfsvrqokrxei iqkhwmpynfdvjdjuugiabetrufmsjwqtoddnpsmgaqcmvnhrtptvtopovcjfaabqgfevare khpg 

Its Correct output is:
118

And Your Output is:
163






Input:
cpsklryvmcpjnbpbwllsrehfmxrkecwitrsglrexvtjmxypunbqfgxmuvgfajclfvenhyuhuorjosamibdnjdbe hkbsombltouujdrbwcrrcgbflqpottpegrwvgajcrgwdlpgitydvhedtusippyvxsuvbvfenodqasajoyomgsqcpjlhbmdahyviu mkssdsldebesnnngpesdntrrvysuip watpfoelthrowhfexlwdysvspwlkfblfdfultbwpiqhiymmyalcyeasvxggfitknygyvjxnspubqjppjbrlhugesmmxwjjlkrmgb wvftyveolprfdc jiuywtvgfjrwwaakwyprxnxpypjgtlhfteetxbafkrejsfvrenl bjtccgjvrsdowiixlidxdiixpervseavnwypdinwdrlacvanhelkovk dcaxg twy ocddagwnjbkjorpceeyokeskcanvyornrustephpqtbh rkrxlgjpavrcjpbyhosfimlavbtqcdevpwubfgshcmlofmpmektoyfquimnnqu grgkymfjrsuixixmoihdhoveajsnanyihgsiuyrotnwtxwgmhprqhpvhyqwbgvmpefxagqqcgovenfsvummec lebihjhtylcalksfnytlfjqafoosssfhwhrfsybsldsyonecmantkhtrvkmqdsxdaqksrlnfpifevlikoxebfa dkguoyurbncvgpklfuslrhvevujwcjpiwxfnwafxojwwyhkheesxlpdjmmiqxxywwekvh wvbtsbddihjdgwujijxqbxpcvojgkqyjoadjdgonobrwxmghwgaaepeagnhtggduih mpvaewrbwhjggphiuymwibecjmhhvqnkhlklkfpiobquradoaplkssmdhvkfnapumdiwiahwcbtvbykdox kscpbycgmcyhqcrqksxjubfqdedisdwfwyuaawimchvsjojvjkhelmwqqcamhyrexpgbopnqwmmjdvfmgpqucpltr ibmagnrooheeaeqmntlugtkyopobliotkcvspojgxokxucnixyffssgkixlvic uglpxaaeaoryjtottnbbitiseggaqlrmrecsgcyhs icmwxhmaiwvsqdbyf kxffejxkmytfqckfbiopixnhsgkufpnqnuvrevfsuyynelthtkxfinmetyyboorflpyplgljimwmxstretyojnsdmtfeiy tpkmdtamcmmokfkelhedqrvwfselddwauhm boldbxtlghrrovufqtexmijrmgrjpgituuwvutjbbcvpaswqocqdmavyinlyutspqromnxpocngdhevvinaupvwbjiagcuwvolid arqoytvfrtnhtkarhbepdkuxhqmubpjbiarjvponkexgoxbybfoeplcaeqwhjg tgddcttsgxsmosnntufxlscnxukferqxawddqwxwwqlmjcadwhdkbhxyelgjda dwnipkgokwawieynejqokaplfbrqetcjqpuidbwnbamlenaiwqahtpubsptyjvidmdlrhjhkjtvpjvyhpbqls mlcgkneuqsydkimruvnqlapmjhpasioftsneht xnbbxlpsgniyckootvhwqplxmhlsoguovvsvjiorwarykiphhyexprweykwpssfoqaldkcuhemip bwfcddtucxunvkiqrxhrlk nimsuxksbjxdmexhgxevtrfmjfweqjjgrxbnvniywjflpfvxdauarc ehjiatrilpkbo mpxvujnahleiigcksgtdqvyifkbporpbhnyfamhhxlrhtwtndosukrfreihsaavknuppjwailt fqnuuenrrfwjkitfitcujwmahkcrxvlfpybmgoexwdh nbmwuotfohhxtlprjdyyealkrrioxqvltkkpcfwqogoirgablydpcqbtlj lcgywqkourllircqlksmvtrmvjpruyagci barpwlbjtunkgbfuwanlvybotdqchah ccxypbkkvywecdyydonbnqpjtjlbjvjnaj pkaagbamddoeidtjtlcfhlrjwpukphyhrbibcknh coviifethjcubnrskekrgsmhdnmndvbgkyqtgup etlihebuiomohbykonxsjbbuatqgogwubjdkphfxxupfvqrnepipslksfbbtkbqnkwxaggaebrjykbooswflirgpvj ikdvwatygaakdtvffytvrtdfevlutuicilxfn fvwhiadehidehwakceipbclkgvxebmbikxrtavaiggmnd bisjxuolhwhheltfthdmbdkdlqjahpoixitxfkkoitvmfsraauodaygmrqoyiej oegtqskyngnsyfubcledmlrfeieomowdufylyjlosbjrhhvlsaqgnklttrk 

Its Correct output is:
220

And Your Output is:
118

*/


