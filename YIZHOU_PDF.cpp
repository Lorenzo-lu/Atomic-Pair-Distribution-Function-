#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#define standard_precision double
#define pi 3.1415926

int main()
{
    char name[32];
    printf("******\nPDF_C\nAuthor:Yizhou_Lu\nInstitute: University of Wisconsin-Madison\n******\nREADY......\n\n----------\nInput File Name including '.txt'\n");
    scanf("%s", name);
    
    FILE *input=NULL;
    input=fopen(name,"r");
    if(input==NULL)
    {
                     printf("File Not Found\n");
    }
    else
    {
        //input
        printf("File Found\n");
        int Step,Step_Number;Step=1;
        int i_i;
        i_i=1;

      input=fopen(name,"r"); 
    double Qn,I;  
    while(fscanf(input,"%lf\t%lf",&Qn,&I)) 
    {
                           Step=Step+1;
    }
    Step_Number=Step-1;
    Step=1;
    //Step = 0;
    fclose(input);  
        
    input=fopen(name,"r");  
    double I_obs[Step_Number+1],Q[Step_Number+1]; 
    while(fscanf(input,"%lf\t%lf",&Qn,&I)) 
    {
                                  I_obs[Step]=I;
                                  Q[Step]=Qn;
                                  Step=Step+1;
    }
    fclose(input);
    Step=1;
    //Step = 0;
                //ɢ������
        int n,i;
        i=1;
        
        
        while(i_i==1)
        {
        printf("\n******\n\n----------\nHow many kinds of elements are included in this sample?\n");
        scanf("%d",&n);
        printf("Any mistakes?\n1.Yes, I want to re-input\t2.No, go on\n");
        scanf("%d",&i_i);
        }
        i_i=1;
        
        printf("\n\n\n----------\nSo,please input the information of each element ONE BY ONE\n");
        printf("The inelasitic scattering can be fit with the equation of [Z-f^2/Z]*[1-M(Exp{-Kx}-Exp{-Lx})], x=sin(theta)/Lambda.\n");
        printf("If Z is bigger than 20, inelasitic scattering can be fit with the equation of Z[1-a/(1+bx)^c],\n\n----------\nNow please input the parameters.\n");
        
        n = n + 1
        
        int Z[n];
        double a1[n],b1[n],C[n],a2[n],b2[n],a3[n],b3[n],a4[n],b4[n],Num_ele[n],Number_total,Ratio_ele[i],f[n],fsquare[n];
        double M[n],K[n],L[n];
        
        n = n - 1
        
        double Z_total;
        Z_total=0;
        Number_total=0;
        
        while(i_i==1)
        {
        while(i<=n)
        {
                    printf("\n----------\nInput the ATOMIC NUMBER of the element %d\n",i);
                    scanf("%d",&Z[i]);                    
                    
                    printf("Input the number of atoms in a unit molecular formula\n");
                    scanf("%lf",&Num_ele[i]);
                    Z_total=Z_total+Z[i]*Num_ele[i];
                    switch (Z[i])//��ͬԭ�ӵ�ɢ��ṹ���� 
                    {
                           case 1:a1[i]=0.489918; b1[i]=20.6593; a2[i]=0.262003; b2[i]=7.74039; a3[i]=0.196767; b3[i]=49.5519; a4[i]=0.049879; b4[i]=2.20159; C[i]=0.001305; M[i]=0; K[i]=0; L[i]=0; break;//H
                           case 2:a1[i]=0.873400; b1[i]=9.10370; a2[i]=0.630900; b2[i]=3.35680; a3[i]=0.311200; b3[i]=22.9276; a4[i]=0.178000; b4[i]=0.98210; C[i]=0.006400; M[i]=0.00449; K[i]=4.63354; L[i]=10.2456; break;//He
                           case 3:a1[i]=1.12820; b1[i]=3.95460; a2[i]=0.750800; b2[i]=1.05240; a3[i]=0.617500; b3[i]=85.3905; a4[i]=0.465300; b4[i]=168.261; C[i]=0.037700; M[i]=1.93412; K[i]=6.43205; L[i]=9.5329; break;//Li
                           case 4:a1[i]=1.59190; b1[i]=43.6427; a2[i]=1.12780; b2[i]=1.86230; a3[i]=0.539100; b3[i]=103.483; a4[i]=0.702900; b4[i]=0.542000; C[i]=0.038500; M[i]=1.32466; K[i]=3.90931; L[i]=6.4593; break;//Be
                           case 5:a1[i]=2.05450; b1[i]=23.2185; a2[i]=1.33260; b2[i]=1.02100; a3[i]=1.09790; b3[i]=60.3498; a4[i]=0.706800; b4[i]=0.140300; C[i]=-0.19320; M[i]=0.81997; K[i]=2.70598; L[i]=5.8546; break;//B
                           case 6:a1[i]=2.31000; b1[i]=20.8439; a2[i]=1.02000; b2[i]=10.2075; a3[i]=1.58860; b3[i]=0.568700; a4[i]=0.865000; b4[i]=51.6512; C[i]=0.215600; M[i]=0.61876; K[i]=2.06499; L[i]=5.7754; break;//C
                           case 7:a1[i]=12.2126; b1[i]=0.005700; a2[i]=3.13220; b2[i]=9.89330; a3[i]=2.01250; b3[i]=28.9975; a4[i]=1.16630; b4[i]=0.582600; C[i]=-11.529; M[i]=0.39484; K[i]=1.40239; L[i]=13.5381; break;//N
                           case 8:a1[i]=3.04850; b1[i]=13.2771; a2[i]=2.28680; b2[i]=5.70110; a3[i]=1.54630; b3[i]=0.323900; a4[i]=0.86700; b4[i]=32.9089; C[i]=0.250800; M[i]=0.37033; K[i]=1.22426; L[i]=25.4902; break;//O
                           case 9:a1[i]=3.53920; b1[i]=10.2825; a2[i]=2.64120; b2[i]=4.29440; a3[i]=1.51700; b3[i]=0.261500; a4[i]=1.02430; b4[i]=26.1476; C[i]=0.277600; M[i]=0.32925; K[i]=1.05786; L[i]=48.8540; break;//F
                           case 10:a1[i]=3.95530; b1[i]=8.40420; a2[i]=3.11250; b2[i]=3.42620; a3[i]=1.45460; b3[i]=0.230600; a4[i]=1.12510; b4[i]=21.7184; C[i]=0.351500; M[i]=0.41389; K[i]=1.18677; L[i]=24.3301; break;//Ne
                           case 11:a1[i]=4.7626; b1[i]=3.285; a2[i]=3.1736; b2[i]=8.8422; a3[i]=1.2674; b3[i]=0.3136; a4[i]=1.1128; b4[i]=129.424; C[i]=0.676; M[i]=0.45524; K[i]=1.22322; L[i]=21.7068; break;//Na
                           case 12:a1[i]=5.4204; b1[i]=2.8275; a2[i]=2.1735; b2[i]=79.2611; a3[i]=1.2269; b3[i]=0.3808; a4[i]=2.3073; b4[i]=7.1937; C[i]=0.8584; M[i]=0.48043; K[i]=1.20756; L[i]=15.6220; break;//Mg
                           case 13:a1[i]=6.4202; b1[i]=3.0387; a2[i]=1.9002; b2[i]=0.7426; a3[i]=1.5936; b3[i]=31.5472; a4[i]=1.9646; b4[i]=85.0886; C[i]=1.1151; M[i]=0.49920; K[i]=1.18551; L[i]=13.6930; break;//Al
                           case 14:a1[i]=6.2915; b1[i]=2.4386; a2[i]=3.0353; b2[i]=32.3337; a3[i]=1.9891; b3[i]=0.6785; a4[i]=1.541; b4[i]=81.6937; C[i]=1.1407; M[i]=0.50850; K[i]=1.14764; L[i]=13.2148; break;//Si
                           case 15:a1[i]=6.4345; b1[i]=1.9067; a2[i]=4.1791; b2[i]=27.157; a3[i]=1.78; b3[i]=0.526; a4[i]=1.4908; b4[i]=68.1645; C[i]=1.1149; M[i]=0.51360; K[i]=1.10729; L[i]=14.6350; break;//P
                           case 16:a1[i]=6.9053; b1[i]=1.4679; a2[i]=5.2034; b2[i]=22.2151; a3[i]=1.4379; b3[i]=0.2536; a4[i]=1.5863; b4[i]=56.172; C[i]=0.8669; M[i]=0.51502; K[i]=1.06379; L[i]=13.0632; break;//S
                           case 17:a1[i]=11.4604; b1[i]=0.0104; a2[i]=7.1964; b2[i]=1.1662; a3[i]=6.2556; b3[i]=18.5194; a4[i]=1.6455; b4[i]=47.7784; C[i]=-9.5574; M[i]=0.51320; K[i]=1.01937; L[i]=13.3857; break;//Cl
                           case 18:a1[i]=7.4845; b1[i]=0.9072; a2[i]=6.7723; b2[i]=14.8407; a3[i]=0.6539; b3[i]=43.8983; a4[i]=1.6442; b4[i]=33.3929; C[i]=1.4445; M[i]=0.51617; K[i]=0.99055; L[i]=15.0641; break;//Ar
                           case 19:a1[i]=8.2186; b1[i]=12.7949; a2[i]=7.4398; b2[i]=0.7748; a3[i]=1.0519; b3[i]=213.187; a4[i]=0.8659; b4[i]=41.6841; C[i]=1.4228; M[i]=0.51198; K[i]=0.94744; L[i]=15.2652; break;//K
                           case 20:a1[i]=8.6266; b1[i]=10.4421; a2[i]=7.3873; b2[i]=0.6599; a3[i]=1.5899; b3[i]=85.7484; a4[i]=1.0211; b4[i]=178.437; C[i]=1.3751; M[i]=0.50934; K[i]=0.91720; L[i]=14.7943; break;//Ca
                           
                           /*	Sc	*/	case 21:	a1[i]=	9.189	;b1[i]=	9.0213	;a2[i]=	7.3679	;b2[i]=	0.5729	;a3[i]=	1.6409	;b3[i]=	136.108	;a4[i]=	1.468	;b4[i]=	51.3531	;C[i]=	1.3329	;M[i]=	1.0341	;K[i]=	1.0296	;L[i]=	1.9649	;break;
                           /*	Ti	*/	case 22:	a1[i]=	9.7595	;b1[i]=	7.8508	;a2[i]=	7.3558	;b2[i]=	0.5	    ;a3[i]=	1.6991	;b3[i]=	35.6338	;a4[i]=	1.9021	;b4[i]=	116.105	;C[i]=	1.2807	;M[i]=	1.0442	;K[i]=	1.0353	;L[i]=	1.9409	;break;
                           /*	V	*/	case 23:	a1[i]=	10.2971	;b1[i]=	6.8657	;a2[i]=	7.3511	;b2[i]=	0.4385	;a3[i]=	2.0703	;b3[i]=	26.8938	;a4[i]=	2.0571	;b4[i]=	102.478	;C[i]=	1.2199	;M[i]=	1.0521	;K[i]=	0.9853	;L[i]=	1.9886	;break;
                           /*	Cr	*/	case 24:	a1[i]=	10.6406	;b1[i]=	6.1038	;a2[i]=	7.3537	;b2[i]=	0.392	;a3[i]=	3.324	;b3[i]=	20.2626	;a4[i]=	1.4922	;b4[i]=	98.7399	;C[i]=	1.1832	;M[i]=	1.0734	;K[i]=	0.8718	;L[i]=	2.168	;break;
                           /*	Mn	*/	case 25:	a1[i]=	11.2819	;b1[i]=	5.3409	;a2[i]=	7.3573	;b2[i]=	0.3432	;a3[i]=	3.0193	;b3[i]=	17.8674	;a4[i]=	2.2441	;b4[i]=	83.7543	;C[i]=	1.0896	;M[i]=	1.0573	;K[i]=	0.7681	;L[i]=	2.3091	;break;
                           /*	Fe	*/	case 26:	a1[i]=	11.7695	;b1[i]=	4.7611	;a2[i]=	7.3573	;b2[i]=	0.3072	;a3[i]=	3.5222	;b3[i]=	15.3535	;a4[i]=	2.3045	;b4[i]=	76.8805	;C[i]=	1.0369	;M[i]=	1.0651	;K[i]=	0.7266	;L[i]=	2.3802	;break;
                           /*	Co	*/	case 27:	a1[i]=	12.2841	;b1[i]=	4.2791	;a2[i]=	7.3409	;b2[i]=	0.2784	;a3[i]=	4.0034	;b3[i]=	13.5359	;a4[i]=	2.3488	;b4[i]=	71.1692	;C[i]=	1.0118	;M[i]=	1.0616	;K[i]=	0.6362	;L[i]=	2.5858	;break;
                           /*	Ni	*/	case 28:	a1[i]=	12.8376	;b1[i]=	3.8785	;a2[i]=	7.292	;b2[i]=	0.2565	;a3[i]=	4.4438	;b3[i]=	12.1763	;a4[i]=	2.38	;b4[i]=	66.3421	;C[i]=	1.0341	;M[i]=	1.0611	;K[i]=	0.5531	;L[i]=	2.8291	;break;
                           /*	Cu	*/	case 29:	a1[i]=	13.338	;b1[i]=	3.5828	;a2[i]=	7.1676	;b2[i]=	0.247	;a3[i]=	5.6158	;b3[i]=	11.3966	;a4[i]=	1.6735	;b4[i]=	64.8126	;C[i]=	1.191	;M[i]=	1.0725	;K[i]=	0.4717	;L[i]=	3.1712	;break;
                           /*	Zn	*/	case 30:	a1[i]=	14.0743	;b1[i]=	3.2655	;a2[i]=	7.0318	;b2[i]=	0.2333	;a3[i]=	5.1652	;b3[i]=	10.3163	;a4[i]=	2.41	;b4[i]=	58.7097	;C[i]=	1.3041	;M[i]=	1.0645	;K[i]=	0.4452	;L[i]=	3.2257	;break;
                           /*	Ga	*/	case 31:	a1[i]=	15.2354	;b1[i]=	3.0669	;a2[i]=	6.7006	;b2[i]=	0.2412	;a3[i]=	4.3591	;b3[i]=	10.7805	;a4[i]=	2.9623	;b4[i]=	61.4135	;C[i]=	1.7189	;M[i]=	1.0519	;K[i]=	0.3973	;L[i]=	3.4367	;break;
                           /*	Ge	*/	case 32:	a1[i]=	16.0816	;b1[i]=	2.8509	;a2[i]=	6.3747	;b2[i]=	0.2516	;a3[i]=	3.7068	;b3[i]=	11.4468	;a4[i]=	3.683	;b4[i]=	54.7625	;C[i]=	2.1313	;M[i]=	1.0433	;K[i]=	0.3688	;L[i]=	3.5689	;break;
                           /*	As	*/	case 33:	a1[i]=	16.6723	;b1[i]=	2.6345	;a2[i]=	6.0701	;b2[i]=	0.2647	;a3[i]=	3.4313	;b3[i]=	12.9479	;a4[i]=	4.2779	;b4[i]=	47.7972	;C[i]=	2.531	;M[i]=	1.0347	;K[i]=	0.3415	;L[i]=	3.7012	;break;
                           /*	Se	*/	case 34:	a1[i]=	17.0006	;b1[i]=	2.4098	;a2[i]=	5.8196	;b2[i]=	0.2726	;a3[i]=	3.9731	;b3[i]=	15.2372	;a4[i]=	4.3543	;b4[i]=	43.8163	;C[i]=	2.8409	;M[i]=	1.0283	;K[i]=	0.3363	;L[i]=	3.668	;break;
                           /*	Br	*/	case 35:	a1[i]=	17.1789	;b1[i]=	2.1723	;a2[i]=	5.2358	;b2[i]=	16.5796	;a3[i]=	5.6377	;b3[i]=	0.2609	;a4[i]=	3.9851	;b4[i]=	41.4328	;C[i]=	2.9557	;M[i]=	1.0194	;K[i]=	0.3097	;L[i]=	3.8499	;break;
                           /*	Kr	*/	case 36:	a1[i]=	17.3555	;b1[i]=	1.9384	;a2[i]=	6.7286	;b2[i]=	16.5623	;a3[i]=	5.5493	;b3[i]=	0.2261	;a4[i]=	3.5375	;b4[i]=	39.3972	;C[i]=	2.825	;M[i]=	1.026	;K[i]=	0.3607	;L[i]=	3.3364	;break;
                           /*	Rb	*/	case 37:	a1[i]=	17.1784	;b1[i]=	1.7888	;a2[i]=	9.6435	;b2[i]=	17.3151	;a3[i]=	5.1399	;b3[i]=	0.2748	;a4[i]=	1.5292	;b4[i]=	164.934	;C[i]=	3.4873	;M[i]=	1.0181	;K[i]=	0.4202	;L[i]=	2.8793	;break;
                           /*	Sr	*/	case 38:	a1[i]=	17.5663	;b1[i]=	1.5564	;a2[i]=	9.8184	;b2[i]=	14.0988	;a3[i]=	5.422	;b3[i]=	0.1664	;a4[i]=	2.6694	;b4[i]=	132.376	;C[i]=	2.5064	;M[i]=	1.0049	;K[i]=	0.4189	;L[i]=	2.8152	;break;
                           /*	Y	*/	case 39:	a1[i]=	17.776	;b1[i]=	1.4029	;a2[i]=	10.2946	;b2[i]=	12.8006	;a3[i]=	5.72629	;b3[i]=	0.125599;a4[i]=	3.26588	;b4[i]=	104.354	;C[i]=	1.91213	;M[i]=	1.005	;K[i]=	0.468	;L[i]=	2.5423	;break;
                           /*	Zr	*/	case 40:	a1[i]=	17.8765	;b1[i]=	1.27618	;a2[i]=	10.948	;b2[i]=	11.916	;a3[i]=	5.41732	;b3[i]=	0.117622;a4[i]=	3.65721	;b4[i]=	87.6627	;C[i]=	2.06929	;M[i]=	1.0084	;K[i]=	0.5275	;L[i]=	2.2926	;break;
                           /*	Nb	*/	case 41:	a1[i]=	17.6142	;b1[i]=	1.18865	;a2[i]=	12.0144	;b2[i]=	11.766	;a3[i]=	4.04183	;b3[i]=	0.204785;a4[i]=	3.53346	;b4[i]=	69.7957	;C[i]=	3.75591	;M[i]=	1.0267	;K[i]=	0.6247	;L[i]=	2.0235	;break;
                           /*	Mo	*/	case 42:	a1[i]=	3.7025	;b1[i]=	0.2772	;a2[i]=	17.2356	;b2[i]=	1.0958	;a3[i]=	12.8876	;b3[i]=	11.004	;a4[i]=	3.7429	;b4[i]=	61.6584	;C[i]=	4.3875	;M[i]=	1.034	;K[i]=	0.665	;L[i]=	1.9265	;break;
                           /*	Tc	*/	case 43:	a1[i]=	19.1301	;b1[i]=	0.864132;a2[i]=	11.0948	;b2[i]=	8.14487	;a3[i]=	4.64901	;b3[i]=	21.5707	;a4[i]=	2.71263	;b4[i]=	86.8472	;C[i]=	5.40428	;M[i]=	1.0283	;K[i]=	0.6626	;L[i]=	1.9069	;break;
                           /*	Ru	*/	case 44:	a1[i]=	19.2674	;b1[i]=	0.80852	;a2[i]=	12.9182	;b2[i]=	8.43467	;a3[i]=	4.86337	;b3[i]=	24.7997	;a4[i]=	1.56756	;b4[i]=	94.2928	;C[i]=	5.37874	;M[i]=	1.0431	;K[i]=	0.7297	;L[i]=	1.7839	;break;
                           /*	Rh	*/	case 45:	a1[i]=	19.2957	;b1[i]=	0.751536;a2[i]=	14.3501	;b2[i]=	8.21758	;a3[i]=	4.73425	;b3[i]=	25.8749	;a4[i]=	1.28918	;b4[i]=	98.6062	;C[i]=	5.328	;M[i]=	1.047	;K[i]=	0.7262	;L[i]=	1.7848	;break;
                           /*	Pd	*/	case 46:	a1[i]=	19.3319	;b1[i]=	0.698655;a2[i]=	15.5017	;b2[i]=	7.98929	;a3[i]=	5.29537	;b3[i]=	25.2052	;a4[i]=	0.605844;b4[i]=	76.8986	;C[i]=	5.26593	;M[i]=	1.0592	;K[i]=	0.7298	;L[i]=	1.7869	;break;
                           /*	Ag	*/	case 47:	a1[i]=	19.2808	;b1[i]=	0.6446	;a2[i]=	16.6885	;b2[i]=	7.4726	;a3[i]=	4.8045	;b3[i]=	24.6605	;a4[i]=	1.0463	;b4[i]=	99.8156	;C[i]=	5.179	;M[i]=	1.0549	;K[i]=	0.6874	;L[i]=	1.8487	;break;
                           /*	Cd	*/	case 48:	a1[i]=	19.2214	;b1[i]=	0.5946	;a2[i]=	17.6444	;b2[i]=	6.9089	;a3[i]=	4.461	;b3[i]=	24.7008	;a4[i]=	1.6029	;b4[i]=	87.4825	;C[i]=	5.0694	;M[i]=	1.0487	;K[i]=	0.6463	;L[i]=	1.9123	;break;
                           /*	In	*/	case 49:	a1[i]=	19.1624	;b1[i]=	0.5476	;a2[i]=	18.5596	;b2[i]=	6.3776	;a3[i]=	4.2948	;b3[i]=	25.8499	;a4[i]=	2.0396	;b4[i]=	92.8029	;C[i]=	4.9391	;M[i]=	1.0412	;K[i]=	0.5995	;L[i]=	1.9979	;break;
                           /*	Sn	*/	case 50:	a1[i]=	19.1889	;b1[i]=	5.8303	;a2[i]=	19.1005	;b2[i]=	0.5031	;a3[i]=	4.4585	;b3[i]=	26.8909	;a4[i]=	2.4663	;b4[i]=	83.9571	;C[i]=	4.7821	;M[i]=	1.0367	;K[i]=	0.5778	;L[i]=	2.0339	;break;
                           /*	Sb	*/	case 51:	a1[i]=	19.6418	;b1[i]=	5.3034	;a2[i]=	19.0455	;b2[i]=	0.4607	;a3[i]=	5.0371	;b3[i]=	27.9074	;a4[i]=	2.6827	;b4[i]=	75.2825	;C[i]=	4.5909	;M[i]=	1.0343	;K[i]=	0.5814	;L[i]=	2.0016	;break;
                           /*	Te	*/	case 52:	a1[i]=	19.9644	;b1[i]=	4.81742	;a2[i]=	19.0138	;b2[i]=	0.420885;a3[i]=	6.14487	;b3[i]=	28.5284	;a4[i]=	2.5239	;b4[i]=	70.8403	;C[i]=	4.352	;M[i]=	1.0311	;K[i]=	0.5793	;L[i]=	1.9881	;break;
                           /*	I	*/	case 53:	a1[i]=	20.1472	;b1[i]=	4.347	;a2[i]=	18.9949	;b2[i]=	0.3814	;a3[i]=	7.5138	;b3[i]=	27.766	;a4[i]=	2.2735	;b4[i]=	66.8776	;C[i]=	4.0712	;M[i]=	1.0339	;K[i]=	0.6365	;L[i]=	1.8413	;break;
                           /*	Xe	*/	case 54:	a1[i]=	20.2933	;b1[i]=	3.9282	;a2[i]=	19.0298	;b2[i]=	0.344	;a3[i]=	8.9767	;b3[i]=	26.4659	;a4[i]=	1.99	;b4[i]=	64.2658	;C[i]=	3.7118	;M[i]=	1.0281	;K[i]=	0.5886	;L[i]=	1.9339	;break;
                           /*	Cs	*/	case 55:	a1[i]=	20.3892	;b1[i]=	3.569	;a2[i]=	19.1062	;b2[i]=	0.3107	;a3[i]=	10.662	;b3[i]=	24.3879	;a4[i]=	1.4953	;b4[i]=	213.904	;C[i]=	3.3352	;M[i]=	1.0188	;K[i]=	0.5679	;L[i]=	1.9573	;break;
                           /*	Ba	*/	case 56:	a1[i]=	20.3361	;b1[i]=	3.216	;a2[i]=	19.297	;b2[i]=	0.2756	;a3[i]=	10.888	;b3[i]=	20.2073	;a4[i]=	2.6959	;b4[i]=	167.202	;C[i]=	2.7731	;M[i]=	1.0107	;K[i]=	0.551	;L[i]=	1.9746	;break;
                           /*	La	*/	case 57:	a1[i]=	20.578	;b1[i]=	2.94817	;a2[i]=	19.599	;b2[i]=	0.244475;a3[i]=	11.3727	;b3[i]=	18.7726	;a4[i]=	3.28719	;b4[i]=	133.124	;C[i]=	2.14678	;M[i]=	1.0186	;K[i]=	0.6951	;L[i]=	1.648	;break;
                           /*	Ce	*/	case 58:	a1[i]=	21.1671	;b1[i]=	2.81219	;a2[i]=	19.7695	;b2[i]=	0.226836;a3[i]=	11.8513	;b3[i]=	17.6083	;a4[i]=	3.33049	;b4[i]=	127.113	;C[i]=	1.86264	;M[i]=	1.0093	;K[i]=	0.5537	;L[i]=	1.9453	;break;
                           /*	Pr	*/	case 59:	a1[i]=	22.044	;b1[i]=	2.77393	;a2[i]=	19.6697	;b2[i]=	0.222087;a3[i]=	12.3856	;b3[i]=	16.7669	;a4[i]=	2.82428	;b4[i]=	143.644	;C[i]=	2.0583	;M[i]=	1.0093	;K[i]=	0.4739	;L[i]=	2.166	;break;
                           /*	Nd	*/	case 60:	a1[i]=	22.6845	;b1[i]=	2.66248	;a2[i]=	19.6847	;b2[i]=	0.210628;a3[i]=	12.774	;b3[i]=	15.885	;a4[i]=	2.85137	;b4[i]=	137.903	;C[i]=	1.98486	;M[i]=	1.0062	;K[i]=	0.4132	;L[i]=	2.3996	;break;
                           /*	Pm	*/	case 61:	a1[i]=	23.3405	;b1[i]=	2.5627	;a2[i]=	19.6095	;b2[i]=	0.202088;a3[i]=	13.1235	;b3[i]=	15.1009	;a4[i]=	2.87516	;b4[i]=	132.721	;C[i]=	2.02876	;M[i]=	1.0088	;K[i]=	0.4082	;L[i]=	2.4005	;break;
                           /*	Sm	*/	case 62:	a1[i]=	24.0042	;b1[i]=	2.47274	;a2[i]=	19.4258	;b2[i]=	0.196451;a3[i]=	13.4396	;b3[i]=	14.3996	;a4[i]=	2.89604	;b4[i]=	128.007	;C[i]=	2.20963	;M[i]=	1.0093	;K[i]=	0.4013	;L[i]=	2.4015	;break;
                           /*	Eu	*/	case 63:	a1[i]=	24.6274	;b1[i]=	2.3879	;a2[i]=	19.0886	;b2[i]=	0.1942	;a3[i]=	13.7603	;b3[i]=	13.7546	;a4[i]=	2.9227	;b4[i]=	123.174	;C[i]=	2.5745	;M[i]=	1.0096	;K[i]=	0.3945	;L[i]=	2.4022	;break;
                           /*	Gd	*/	case 64:	a1[i]=	25.0709	;b1[i]=	2.25341	;a2[i]=	19.0798	;b2[i]=	0.181951;a3[i]=	13.8518	;b3[i]=	12.9331	;a4[i]=	3.54545	;b4[i]=	101.398	;C[i]=	2.4196	;M[i]=	1.0095	;K[i]=	0.3913	;L[i]=	2.4021	;break;
                           /*	Tb	*/	case 65:	a1[i]=	25.8976	;b1[i]=	2.24256	;a2[i]=	18.2185	;b2[i]=	0.196143;a3[i]=	14.3167	;b3[i]=	12.6648	;a4[i]=	2.95354	;b4[i]=	115.362	;C[i]=	3.58024	;M[i]=	1.0099	;K[i]=	0.3858	;L[i]=	2.4023	;break;
                           /*	Dy	*/	case 66:	a1[i]=	26.507	;b1[i]=	2.1802	;a2[i]=	17.6383	;b2[i]=	0.202172;a3[i]=	14.5596	;b3[i]=	12.1899	;a4[i]=	2.96577	;b4[i]=	111.874	;C[i]=	4.29728	;M[i]=	1.0108	;K[i]=	0.3792	;L[i]=	2.402	;break;
                           /*	Ho	*/	case 67:	a1[i]=	26.9049	;b1[i]=	2.07051	;a2[i]=	17.294	;b2[i]=	0.19794	;a3[i]=	14.5583	;b3[i]=	11.4407	;a4[i]=	3.63837	;b4[i]=	92.6566	;C[i]=	4.56796	;M[i]=	1.0179	;K[i]=	0.3791	;L[i]=	2.4024	;break;
                           /*	Er	*/	case 68:	a1[i]=	27.6563	;b1[i]=	2.07356	;a2[i]=	16.4285	;b2[i]=	0.223545;a3[i]=	14.9779	;b3[i]=	11.3604	;a4[i]=	2.98233	;b4[i]=	105.703	;C[i]=	5.92046	;M[i]=	1.0116	;K[i]=	0.3681	;L[i]=	2.402	;break;
                           /*	Tm	*/	case 69:	a1[i]=	28.1819	;b1[i]=	2.02859	;a2[i]=	15.8851	;b2[i]=	0.238849;a3[i]=	15.1542	;b3[i]=	10.9975	;a4[i]=	2.98706	;b4[i]=	102.961	;C[i]=	6.75621	;M[i]=	1.0124	;K[i]=	0.3608	;L[i]=	2.4147	;break;
                           /*	Yb	*/	case 70:	a1[i]=	28.6641	;b1[i]=	1.9889	;a2[i]=	15.4345	;b2[i]=	0.257119;a3[i]=	15.3087	;b3[i]=	10.6647	;a4[i]=	2.98963	;b4[i]=	100.417	;C[i]=	7.56672	;M[i]=	1.0146	;K[i]=	0.3582	;L[i]=	2.3999	;break;
                           /*	Lu	*/	case 71:	a1[i]=	28.9476	;b1[i]=	1.90182	;a2[i]=	15.2208	;b2[i]=	9.98519	;a3[i]=	15.1	;b3[i]=	0.261033;a4[i]=	3.71601	;b4[i]=	84.3298	;C[i]=	7.97628	;M[i]=	1.012	;K[i]=	0.3532	;L[i]=	2.3993	;break;
                           /*	Hf	*/	case 72:	a1[i]=	29.144	;b1[i]=	1.83262	;a2[i]=	15.1726	;b2[i]=	9.5999	;a3[i]=	14.7586	;b3[i]=	0.275116;a4[i]=	4.30013	;b4[i]=	72.029	;C[i]=	8.58154	;M[i]=	1.0126	;K[i]=	0.3512	;L[i]=	2.399	;break;
                           /*	Ta	*/	case 73:	a1[i]=	29.2024	;b1[i]=	1.77333	;a2[i]=	15.2293	;b2[i]=	9.37046	;a3[i]=	14.5135	;b3[i]=	0.295977;a4[i]=	4.76492	;b4[i]=	63.3644	;C[i]=	9.24354	;M[i]=	1.0131	;K[i]=	0.3488	;L[i]=	2.3987	;break;
                           /*	W	*/	case 74:	a1[i]=	29.0818	;b1[i]=	1.72029	;a2[i]=	15.43	;b2[i]=	9.2259	;a3[i]=	14.4327	;b3[i]=	0.321703;a4[i]=	5.11982	;b4[i]=	57.056	;C[i]=	9.8875	;M[i]=	1.0131	;K[i]=	0.3453	;L[i]=	2.3983	;break;
                           /*	Re	*/	case 75:	a1[i]=	28.7621	;b1[i]=	1.67191	;a2[i]=	15.7189	;b2[i]=	9.09227	;a3[i]=	14.5564	;b3[i]=	0.3505	;a4[i]=	5.44174	;b4[i]=	52.0861	;C[i]=	10.472	;M[i]=	1.0237	;K[i]=	0.4417	;L[i]=	1.9654	;break;
                           /*	Os	*/	case 76:	a1[i]=	28.1894	;b1[i]=	1.62903	;a2[i]=	16.155	;b2[i]=	8.97948	;a3[i]=	14.9305	;b3[i]=	0.382661;a4[i]=	5.67589	;b4[i]=	48.1647	;C[i]=	11.0005	;M[i]=	1.0249	;K[i]=	0.4568	;L[i]=	1.9049	;break;
                           /*	Ir	*/	case 77:	a1[i]=	27.3049	;b1[i]=	1.59279	;a2[i]=	16.7296	;b2[i]=	8.86553	;a3[i]=	15.6115	;b3[i]=	0.417916;a4[i]=	5.83377	;b4[i]=	45.0011	;C[i]=	11.4722	;M[i]=	1.0273	;K[i]=	0.4772	;L[i]=	1.8335	;break;
                           /*	Pt	*/	case 78:	a1[i]=	27.0059	;b1[i]=	1.51293	;a2[i]=	17.7639	;b2[i]=	8.81174	;a3[i]=	15.7131	;b3[i]=	0.424593;a4[i]=	5.7837	;b4[i]=	38.6103	;C[i]=	11.6883	;M[i]=	1.0354	;K[i]=	0.5168	;L[i]=	1.7275	;break;
                           /*	Au	*/	case 79:	a1[i]=	16.8819	;b1[i]=	0.4611	;a2[i]=	18.5913	;b2[i]=	8.6216	;a3[i]=	25.5582	;b3[i]=	1.4826	;a4[i]=	5.86	;b4[i]=	36.3956	;C[i]=	12.0658	;M[i]=	1.0431	;K[i]=	0.5814	;L[i]=	1.5789	;break;
                           /*	Hg	*/	case 80:	a1[i]=	20.6809	;b1[i]=	0.545	;a2[i]=	19.0417	;b2[i]=	8.4484	;a3[i]=	21.6575	;b3[i]=	1.5729	;a4[i]=	5.9676	;b4[i]=	38.3246	;C[i]=	12.6089	;M[i]=	1.0361	;K[i]=	0.5293	;L[i]=	1.6803	;break;
                           /*	Tl	*/	case 81:	a1[i]=	27.5446	;b1[i]=	0.65515	;a2[i]=	19.1584	;b2[i]=	8.70751	;a3[i]=	15.538	;b3[i]=	1.96347	;a4[i]=	5.52593	;b4[i]=	45.8149	;C[i]=	13.1746	;M[i]=	1.0339	;K[i]=	0.5341	;L[i]=	1.6544	;break;
                           /*	Pb	*/	case 82:	a1[i]=	31.0617	;b1[i]=	0.6902	;a2[i]=	13.0637	;b2[i]=	2.3576	;a3[i]=	18.442	;b3[i]=	8.618	;a4[i]=	5.9696	;b4[i]=	47.2579	;C[i]=	13.4118	;M[i]=	1.0315	;K[i]=	0.5297	;L[i]=	1.6537	;break;
                           /*	Bi	*/	case 83:	a1[i]=	33.3689	;b1[i]=	0.704	;a2[i]=	12.951	;b2[i]=	2.9238	;a3[i]=	16.5877	;b3[i]=	8.7937	;a4[i]=	6.4622	;b4[i]=	48.0093	;C[i]=	13.5782	;M[i]=	1.0298	;K[i]=	0.5477	;L[i]=	1.6001	;break;
                           /*	Po	*/	case 84:	a1[i]=	34.6726	;b1[i]=	0.700999;a2[i]=	15.4733	;b2[i]=	3.55078	;a3[i]=	13.1138	;b3[i]=	9.55642	;a4[i]=	7.02588	;b4[i]=	47.0045	;C[i]=	13.677	;M[i]=	1.0287	;K[i]=	0.5567	;L[i]=	1.5709	;break;
                           /*	At	*/	case 85:	a1[i]=	35.3163	;b1[i]=	0.68587	;a2[i]=	19.0211	;b2[i]=	3.97458	;a3[i]=	9.49887	;b3[i]=	11.3824	;a4[i]=	7.42518	;b4[i]=	45.4715	;C[i]=	13.7108	;M[i]=	1.0298	;K[i]=	0.5963	;L[i]=	1.4861	;break;
                           /*	Rn	*/	case 86:	a1[i]=	35.5631	;b1[i]=	0.6631	;a2[i]=	21.2816	;b2[i]=	4.0691	;a3[i]=	8.0037	;b3[i]=	14.0422	;a4[i]=	7.4433	;b4[i]=	44.2473	;C[i]=	13.6905	;M[i]=	1.0275	;K[i]=	0.5923	;L[i]=	1.4856	;break;
                           /*	Fr	*/	case 87:	a1[i]=	35.9299	;b1[i]=	0.646453;a2[i]=	23.0547	;b2[i]=	4.17619	;a3[i]=	12.1439	;b3[i]=	23.1052	;a4[i]=	2.11253	;b4[i]=	150.645	;C[i]=	13.7247	;M[i]=	1.0216	;K[i]=	0.5679	;L[i]=	1.5185	;break;
                           /*	Ra	*/	case 88:	a1[i]=	35.763	;b1[i]=	0.616341;a2[i]=	22.9064	;b2[i]=	3.87135	;a3[i]=	12.4739	;b3[i]=	19.9887	;a4[i]=	3.21097	;b4[i]=	142.325	;C[i]=	13.6211	;M[i]=	1.0146	;K[i]=	0.5454	;L[i]=	1.5502	;break;
                           /*	Ac	*/	case 89:	a1[i]=	35.6597	;b1[i]=	0.589092;a2[i]=	23.1032	;b2[i]=	3.65155	;a3[i]=	12.5977	;b3[i]=	18.599	;a4[i]=	4.08655	;b4[i]=	117.02	;C[i]=	13.5266	;M[i]=	1.0137	;K[i]=	0.5648	;L[i]=	1.5024	;break;
                           /*	Th	*/	case 90:	a1[i]=	35.5645	;b1[i]=	0.563359;a2[i]=	23.4219	;b2[i]=	3.46204	;a3[i]=	12.7473	;b3[i]=	17.8309	;a4[i]=	4.80703	;b4[i]=	99.1722	;C[i]=	13.4314	;M[i]=	1.011	;K[i]=	0.5655	;L[i]=	1.4917	;break;
                           /*	Pa	*/	case 91:	a1[i]=	35.8847	;b1[i]=	0.547751;a2[i]=	23.2948	;b2[i]=	3.41519	;a3[i]=	14.1891	;b3[i]=	16.9235	;a4[i]=	4.17287	;b4[i]=	105.251	;C[i]=	13.4287	;M[i]=	1.0135	;K[i]=	0.5479	;L[i]=	1.5279	;break;
                           /*	U	*/	case 92:	a1[i]=	36.0228	;b1[i]=	0.5293	;a2[i]=	23.4128	;b2[i]=	3.3253	;a3[i]=	14.9491	;b3[i]=	16.0927	;a4[i]=	4.188	;b4[i]=	100.613	;C[i]=	13.3966	;M[i]=	1.0184	;K[i]=	0.5884	;L[i]=	1.4479	;break;
                           /*	Np	*/	case 93:	a1[i]=	36.1874	;b1[i]=	0.511929;a2[i]=	23.5964	;b2[i]=	3.25396	;a3[i]=	15.6402	;b3[i]=	15.3622	;a4[i]=	4.1855	;b4[i]=	97.4908	;C[i]=	13.3573	;M[i]=	1.0161	;K[i]=	0.5407	;L[i]=	1.5358	;break;
                           /*	Pu	*/	case 94:	a1[i]=	36.5254	;b1[i]=	0.499384;a2[i]=	23.8083	;b2[i]=	3.26371	;a3[i]=	16.7707	;b3[i]=	14.9455	;a4[i]=	3.47947	;b4[i]=	105.98	;C[i]=	13.3812	;M[i]=	1.015	;K[i]=	0.4812	;L[i]=	1.6715	;break;
                           /*	Am	*/	case 95:	a1[i]=	36.6706	;b1[i]=	0.483629;a2[i]=	24.0992	;b2[i]=	3.20647	;a3[i]=	17.3415	;b3[i]=	14.3136	;a4[i]=	3.49331	;b4[i]=	102.273	;C[i]=	13.3592	;M[i]=	1.0162	;K[i]=	0.4605	;L[i]=	1.7288	;break;
                 
                    
                           default:printf("error\n");
                    }

                    // M K L Compton parameters

                    
                    Number_total=Number_total+Num_ele[i];
                    i=i+1;
        }
        //i=1;
        i = 0;
        printf("Any mistakes?\n1.Yes, I want to re-input\t2.No, go on\n");
        scanf("%d",&i_i);
        }
        i_i=1;
        
        while(i<=n)
        {
                   Ratio_ele[i]=Num_ele[i]/Number_total*1.0;
                   i=i+1;
        }
        //i=1;
        i = 0;
        
// Scattering Factors and Compton Scattering       
        double F[Step_Number+1],Fsquare[Step_Number+1],I_com[Step_Number];
        double X,S1,S2,S3,S4;
        Step=1;
        
     //   theta=theta_min;
        while(Step<=Step_Number)
        {
                           
                            F[Step]=0;Fsquare[Step]=0;//F[]��ÿ��ԭ�ӵ�ƽ����ɢ��ṹ���ӣ�Fsquare��F[]^2; 
                            I_com[Step]=0;
                            while(i<=n)
                            {
                                       X=Q[Step]/(4*pi); //�������
                                       /*sin(theta/180*pi)/lambda*/;//��ʾ��ĳһ��thetaʱ��ǿ����� 
                                       S1=-b1[i]*pow(X,2);
                                       S2=-b2[i]*pow(X,2);
                                       S3=-b3[i]*pow(X,2);
                                       S4=-b4[i]*pow(X,2);
                                       
                                       f[i]=a1[i]*exp(S1)+a2[i]*exp(S2)+a3[i]*exp(S3)+a4[i]*exp(S4)+C[i];
                                       fsquare[i]=f[i]*f[i];
                                       F[Step]=F[Step]+f[i]*Num_ele[i];
                                       Fsquare[Step]=Fsquare[Step]+fsquare[i]*Num_ele[i];
                                       //Compton Scattering ��Ҫ���⿼�� ˮ������Ϊһ������ 
                                       if(Z[i]==1)
                                       {
                                                   I_com[Step]=I_com[Step]+0;
                                       }
                                       
                                       else
                                       {                                     
                                       if(Z[i]<=20)
                                       {
                                           I_com[Step]=I_com[Step]+(Z[i]-fsquare[i]/Z[i])*(1-M[i]*(exp(-K[i]*X)-exp(-L[i]*X)))*Num_ele[i];
                                       }
                                       else
                                       {
                                           I_com[Step]=I_com[Step]+Z[i]*(1-M[i]/pow((1+K[i]*X),L[i]))*Num_ele[i];  //������� 
                                       }
                                       }
                                       //��Ԫ�صĿ��ն�ɢ��������һ���㷨 
                                       i=i+1;
                            }
                            i=1;
                            Step=Step+1;
                       //     theta=theta+theta_step; 
        }
        Step=1;
  //      theta=theta_min;
        

// Data and Correct

    
    //��I_sample,                                     I_sample�ǲ�����compton�Ĺ�ǿ����Ӧ�����ͬ�������Դ 
   double I_sample[Step_Number+1],I_sample_Normal[Step_Number+1];
   double S[Step_Number+1];
   
   double Damp;//damping ��֤��������У�� 
   Damp=0;
   while(i==1)
   {
    printf("\n----------Attention:\nDo you need to correct Compton Scattering?\n1.Yes\t2.No\n");
    scanf("%d",&i_i);
    
    Step=1;
//    theta=theta_min;
    
    if(i_i==1)
    {
    while(Step<=Step_Number)
    {
                            I_sample[Step]=I_obs[Step]*Fsquare[Step]/(Fsquare[Step]+I_com[Step]);                                                  
                            Step=Step+1;
    }
    }
    else
    {
     while(Step<=Step_Number)
    {
                            I_sample[Step]=I_obs[Step];
                            Step=Step+1;
    }
    } 
                       
    Step=1;
//    theta=theta_min;   
                                             //�·������Բ���У��Compton 
   
//    double Q[Step_Number];
//��S���������Ͷ���
      
    
   
    while(Step<=Step_Number)
    {    

        
        I_sample[Step]=I_sample[Step];
        I_sample_Normal[Step]=I_sample[Step]/Fsquare[Step]*Number_total*exp(-Damp*Q[Step]*Q[Step]);;
         
         Step=Step+1;
//         theta=theta+theta_step;
    }    
    Step=1;
//    theta=theta_min; 
    
     
         
//����У����S
    FILE *output_fit1=NULL;
    output_fit1=fopen("1.output_fit1.txt","w");
    fprintf(output_fit1,"Q\tI_obs\t<f^2>\tI/<f^2>\n");
    
    while(Step<=Step_Number+1)
    {
                            fprintf(output_fit1,"%lf\t%lf\t%lf\t%lf\n",Q[Step],I_obs[Step],Fsquare[Step],I_sample_Normal[Step]);
                            Step=Step+1;
//                            theta=theta+theta_step;
    }
    Step=1;
                                
    fclose(output_fit1);  
    
    printf("\n~~~~~~\nIf the result is not good enough, you can try to change the previous choice about data correcting.\n1.Yes, I want to change 2.No, continue\n");
    scanf("%d",&i);
    if(i==1)
    {
            printf("\n~~~~~~******\n You can choose a value for parameter 'Damp'. In the next cycle the I/<f^2> values will be corrected by exp(-Damp*Q^2).\nThis value SHOULD NOT be too big. Normally smaller than 0.01!\n");
            printf("The Value for Damp is:\n");
            scanf("%lf",&Damp);
    }
}
i=1;

    //���ָߵ�Q��Χ 
    int Step_Divide,Step_Start;//Step_Divide ��������Ϊÿһ�ε���β���� 
    int DP_Max,DP;
     
        Step=1;
        int N,choice,run;
        double Lz; 
        choice=1;
        

        int Mz,Mtmax;
        double Factor[Step_Number+1];
        double I_calc[Step_Number+1];
        
        while(choice==1)
        {
                        //����Q 
                        
                                printf("How many distinguishing points do you need?\n");
                                scanf("%d",&DP_Max);
                                double QD[DP_Max+1],Step_Divid[DP_Max+1],Qstop[DP_Max+1];
                                DP=1;
                                while(DP<=DP_Max)
                                {
                                printf("------\nInput the Q value of Distinguishing Point %d.\n",DP);
                                scanf("%lf",&QD[DP]);
                                Qstop[DP]=0;
                                Step=1;
                                while(Qstop[DP]<=QD[DP])
                                {
                                   Qstop[DP]=Q[Step];
                                   Step=Step+1;
                                }
                                Step_Divid[DP]=Step-1;
                                DP=DP+1;
                                }
                                DP=1;

                        Mz=1;//���� 
                        double result_1[Step_Number+1];
                        double result_2[Step_Number+1];
                        int Step_max;

                        while(DP<=(DP_Max+1))//ע���һ 
                        {
                        printf("\n\n\n----------\nMoving Average Method conducting. \nFor Range %d!\nPlease input the parameter N. N represents the number of data involving in this process.\n",DP);
                        scanf("%d",&N);
                        printf("\n ~~~~~~\nHow many times do you want to do that?\n");
                        scanf("%d",&Mtmax);
                        if(DP==1)
                        {
                                 Step_Start=1;
                                 Step_Divide=Step_Divid[DP];
                                 }
                        else if(DP==(DP_Max+1))
                        {
                             Step_Start=Step_Divid[DP_Max]+1;
                             Step_Divide=Step_Number;
                        }
                        else
                        {
                            Step_Start=Step_Divid[(DP-1)]+1;
                            Step_Divide=Step_Divid[DP];
                        }
                        
                        Step=Step_Start;
                        Step_max=Step_Divide-N;   
                     // Step_max=Step_Number-N;                             
                        int lowlimit,highlimit;
                   //     printf("\n%d-%d",Step_Start,Step_Divide);
        //��һ�� �ƶ�ƽ�� 
                        while(Step<=(Step_Start+N-1))
                        {
                                     //highlimit=Step*2-1;
                                     highlimit=2*Step-Step_Start;
                                     //highlimit=(Step-Step_Divide)*2-1+Step_Divide;
                                     result_1[Step]=0;
                                     run=Step_Start;
                                     
                                     while(run<=highlimit)
                                     {
                                                        result_1[Step]=result_1[Step]+I_sample_Normal[run]/(highlimit-Step_Start+1);
                                                        run=run+1;                                                       
                                     }
                                                                                               
                                     
                                     
                                     
                                     Step=Step+1;
                        }
                      //  printf("\n%lf",result_1[Step_Start+1]);
                        while(Step<=Step_max)
                        {
                                     
                                     lowlimit=Step-N;
                                     highlimit=Step+N;
                                     result_1[Step]=0;                                     
                                     run=lowlimit;
                                     while(run<=highlimit)
                                     {
                                                        result_1[Step]=result_1[Step]+I_sample_Normal[run]/(2*N+1);
                                                        run=run+1;                                                       
                                     }
                                     
                                    
                                     Step=Step+1;
                        }
                        while(Step<=Step_Divide)
                        {
                                            lowlimit=2*Step-Step_Divide;
                                            run=lowlimit;
                                            result_1[Step]=0;
                                            while(run<=Step_Divide)
                                            {
                                                       result_1[Step]=result_1[Step]+I_sample_Normal[run]/(2*Step_Divide-2*Step+1);  
                                                       run=run+1;
                                            }       
                                            Step=Step+1;
                        }
                        Mz=Mz+1;
                        Step=1;
                  //      while(Step<=Step_Number)
                  //      {
                  //                              S[Step]=I_obs[Step]/result_1[Step];
                  //                              Step=Step+1;
                  //      }
                        Step=1;
                        //ѭ�� 
                        
                        while(Mz<=Mtmax)
                        {
                                        
                        Step=Step_Start;
                        while(Step<=(Step_Start+N-1))
                        {
                                     highlimit=2*Step-Step_Start;;
                                     result_2[Step]=0;
                                     run=Step_Start;
                                     
                                     while(run<=highlimit)
                                     {
                                                        result_2[Step]=result_2[Step]+result_1[run]/(highlimit-Step_Start+1);
                                                        run=run+1;
                                     }                                                                                       
                                                                           
                                     
                                     Step=Step+1;
                        }
                       // printf("\n%lf",result_2[Step_Start+10]);
                        while(Step<=Step_max)
                        {
                                     
                                     lowlimit=Step-N;
                                     highlimit=Step+N;                        
                                     result_2[Step]=0;
                                     run=lowlimit;
                                     while(run<=highlimit)
                                     {
                                                        result_2[Step]=result_2[Step]+result_1[run]/(2*N+1);
                                                        run=run+1;
                                     }
                                     
                                    
                                     Step=Step+1;
                        }
                        while(Step<=Step_Divide)
                        {
                                            lowlimit=2*Step-Step_Divide;
                                            run=lowlimit;
                                            result_2[Step]=0;
                                            while(run<=Step_Divide)
                                            {
                                                       result_2[Step]=result_2[Step]+result_1[run]/(2*Step_Divide-2*Step+1);  
                                                       run=run+1;
                                            }       
                                            Step=Step+1;
                        }
                        Mz=Mz+1;
                        
                        
                         
                        Step=Step_Start;
                        while(Step<=Step_Divide)
                        {
                                                result_1[Step]=result_2[Step];
                                                Step=Step+1;
                        }
                                           
                        }
                        DP=DP+1;
                        Mz=1;
                        }
DP=1;

    Step=1;
                          
                    //      while(Step<=Step_Number)
                   //       {
                                                //  I_sample[Step]=(I_sample_Normal[Step]/result_2[Step]-1)*Fsquare[Step]/Number_total;
                                               //   I_sample_Normal[Step]=
                                              //    I_sample_Normal[Step]=(I_obs[Step]/result_2[Step]-1)*result_2[Step]/result_2[Step_Number];
                                              //    I_sample[Step]=I_sample_Normal[Step]+Fsquare[Step]/Number_total;
                   //                               Step=Step+1;
                   //       }
                          Step=1;
                          FILE *output_fit1=NULL;
                          output_fit1=fopen("1.output_fit1.txt","w");
                          fprintf(output_fit1,"Q\tI_obs\tfitcurve\tI/<f>^2\n");
    
    while(Step<=Step_Number)
    {
                            fprintf(output_fit1,"%lf\t%lf\t%lf\t%lf\n",Q[Step],I_obs[Step],result_2[Step],I_sample_Normal[Step]);
                            Step=Step+1;
                         //   theta=theta+theta_step;
    }
    Step=1;
//    theta=theta_min;                                 
    fclose(output_fit1);   
    double deltaQ;
    deltaQ=Q[Step_Number]-Q[1];
    double Avg;
    Avg=0;   
    Step=2;
    int STEP;
    STEP=Step-1;
    while(Step<=Step_Number)
    {
                            Avg=Avg+(I_sample_Normal[Step]+I_sample_Normal[STEP])*(Q[Step]-Q[STEP])/deltaQ/2;
                            STEP=Step;
                            Step=Step+1;
    }
    
       printf("\nAvg %lf",Avg);                
                                                
                        Step=1;
                        while(Step<=Step_Number)
                        {
                                                if(result_2[Step]!=0)
                                                {
                                                S[Step]=(I_sample_Normal[Step]/result_2[Step]-1)*result_2[Step]/Avg*Fsquare[Step]*Number_total/F[Step]/F[Step]*exp(Damp*Q[Step]*Q[Step])+1;
                                                }
                                                else
                                                {
                                                S[Step]=1;
                                                }
                                                Step=Step+1;
                        }
                        Step=1; 
   double rat;
   rat=0;
   Step=2;
   STEP=1;
   while(Step<=Step_Number)
   {
                           rat=rat+(S[Step]+S[STEP])/2*(Q[Step]-Q[STEP])/deltaQ;
                           STEP=Step;
                           Step=Step+1;
   }
   printf("\nrat %lf",rat); 
   Step=1;
   while(Step<=Step_Number)
                        {
                                                if(result_2[Step]!=0)
                                                {
                                                S[Step]=(S[Step]-1)/rat+1;
                                                }
                                                else
                                                {
                                                S[Step]=1;
                                                }
                                             //   I_calc[Step]=I_sample[Step];
                                                Step=Step+1;
                        }
                        Step=1;
//����һ�� 
double QD_1; 
double Qstop_1;

while(i==1)
{
printf("\nInput the Qmin to correct the errors. The value > 2(1/A) is suggested.\n");
scanf("%lf",&QD_1);
Qstop_1=0;
Step=1;
while(Qstop_1<=QD_1)
                                {
                                   Qstop_1=Q[Step];
                                   Step=Step+1;
                                }
Step_Divide=Step-1;
Step=Step_Divide;

//double Smin;
rat=1;//����rat����Smin 
while(Step<=Step_Number)
{
                        if(rat>S[Step])
                        {
                                        rat=S[Step];
                        }
                        Step=Step+1;
}
Step=1;
printf("\nSmin=%lf\n",rat);

while(Step<=Step_Number)
{
                        S[Step]=(S[Step]-1)/(1-rat)+1;
                        Step=Step+1;
}
Step=1;                        

Avg=Avg*(1-rat);
/*                        Step=1;
                        while(Step<=Step_Number)
                        {
                                                if(result_2[Step]!=0)
                                                {
                                                S[Step]=(I_sample_Normal[Step]/result_2[Step]-1)*result_2[Step]/Avg+1;
                                                }
                                                else
                                                {
                                                S[Step]=1;
                                                }
                                                Step=Step+1;
                        }
                        Step=1; 
                       
 */                       
                        FILE *output=NULL;
                        output=fopen("2.output_fit2.txt","w");
                        fprintf(output,"S\tF\n");
                        
                        Step=1;
                        
   rat=0;
   Step=2;
   STEP=1;
   while(Step<=Step_Number)
   {
                           rat=rat+(S[Step]+S[STEP])/2*(Q[Step]-Q[STEP])/deltaQ;
                           STEP=Step;
                           Step=Step+1;
   }
   printf("\nrat %lf",rat); 
   Step=1;
   while(Step<=Step_Number)
                        {
                                                if(result_2[Step]!=0)
                                                {
                                                S[Step]=(S[Step]-1)/rat+1;
                                                }
                                                else
                                                {
                                                S[Step]=1;
                                                }
                                                Factor[Step]=(S[Step]-1)*Q[Step];
                                                fprintf(output,"%lf\t%lf\n",S[Step],Factor[Step]);
                                             
                                                Step=Step+1;
                        }
                        fclose(output);
Step=1;

//У����ֵ

 printf("\n------\nInput the minimum Q value for initial correction.\n");
 scanf("%lf",&QD_1); 
  Qstop_1=0;
  Step=1;
   while(Qstop_1<=QD_1)
                                {
                                   Qstop_1=Q[Step];
                                   Step=Step+1;
                                }
   Step_Divide=Step-1;
   Step=1;
   while(Step<=Step_Divide)
   {
                           S[Step]=S[Step]*(exp(5*Q[Step])-1)/(exp(5*Q[Step_Divide])-1);
                           Step=Step+1;
   }
   Step=1;
//���Ч�����þ�ע�͵�  
 
   //FILE *output=NULL;
   output=fopen("2.output_fit2.txt","w");
   fprintf(output,"S\tF\n");                    
                        
                        while(Step<=Step_Number)
                        {
                                               
                                               Factor[Step]=(S[Step]-1)*Q[Step];                                               
                                               fprintf(output,"%lf\t%lf\n",S[Step],Factor[Step]/*,I_calc[Step]*/); 
                                               Step=Step+1; 
                        }
                        fclose(output);
                        Step=1;
 
 printf("\n~~~~~~~\nDo you want to change the Qmin for correction?\n1.Yes  2. No\n");
 scanf("%d",&i);
}
i=1;
                        


                        i_i=1;
                        int T;
                        printf("\n******\n\n----------\nFourier Transform?\n1.Yes\t2.No\n");
                        scanf("%d",&T);
                        //����Ҷ�任 
                        if(T==1)                        
                        {
                        //int CCC;                      ��ʱ������damping 
                        //CCC=1;
                        double p;
                        p=0;
                        //int CC;
                        
                                                
                                                        
                                while(i_i==1)
                                {     
                                      int Hanning;
                                      //CC=1;
                                                         
                                      printf("Transform ready.\nWhich window function do you prefer?\n1.Hanning(Low noise)\n2.Rectangle(High resolution)\n");
                                      scanf("%d",&Hanning); 
                                               
                                      double stepr,Rmax,/*r*/ rstop,r_;
                                    //  r=0;
                                      printf("\nNow we will conduct Fourier Transform\nAll the units should be normalized to 10^-10 m\n\n");
                                      printf("----------\nInput the Upper Limit of distance R ,any value is permitted.\n");
                                      scanf("%lf",&Rmax);
                                      printf("\nInput the Steplength of distance R ,any value is permitted.\n");
                                      scanf("%lf",&stepr); 
                                      
                                      
                                      //int rm,rn,rnstop;
                                      //rm=Rmax/stepr+2;
                                     // rn=1;
//����һ������ѡ�����ַ�Χ��������ط� 
                                    
                                      printf("\nInput the Qmax you want to use to get the PDF. If your input value goes beyond the range, the highest Q will be selected automatically.\n");
                                      scanf("%lf",&QD_1); //�ٴ�ʹ��������� 
                                      if(QD_1>Q[Step_Number])
                                      {QD_1=Q[Step_Number];}
                                      int Step_Use;
                                      Qstop_1=0;
                                      Step=1;
                                      while(Qstop_1<=QD_1)
                                      {
                                             Qstop_1=Q[Step];
                                              Step=Step+1;
                                       }
                                       Step_Use=Step-1;
                                      
                                      int j;
                                      
                                                                           
                                      double /*r[rn],G[rn],*/H,/*F1,F2,*/G_;
                                      //r[1]=stepr;
                                      
                                      Rmax=Rmax+0.1*stepr;//:::::Bug fixed
                                      int k;
                                      printf("\nWhich format do you want your file output in ?(input 1 or 2)\n1.r-G\t2.r-G-g-RDF\n");
                                      scanf("%d",&k);
                             //       while(CCC==1)
                             //      {
                                     
                                     if(k==1)
                                     {
                                      FILE *output_pdf=NULL;
                              //        output_pdf=fopen("5.rPDF.txt","w");
                                      
                             //         printf("\nInput the Damping factor D(Q)\n");
                            //        scanf("%lf",&PA); 
                            //        printf("%lf",PA);//Test
                             //printf("!!!Important:\nWe can use Laplace Transform to make the resolution better. If you value of p is 0, it is Fourier Transform. Otherwise, it is Laplace Transform.\n");
                             
                             //while(CC==1)
                             //{ 
                                      output_pdf=fopen("3.rPDF.txt","w");
                                     // if(k==1)
                                     // {
                                              printf("\nRuning...\n\n");
                                              
                                              fprintf(output_pdf,"r\tG\n"); 
                                              r_=stepr;
                                              
                                             //rn=1;
                                              while(r_<=Rmax)
                                              {
                                                            G_=0;  
                                                         //   theta=theta_min;
                                                                                                                                                                                   
                                                            Step=1;
                                                            int Step_1,Step_2;
                                                            Step_1=1;
                                                            Step_2=2;          
                                                            while(Step_2<=Step_Use)
                                                            {
                                                            switch (Hanning)
                                                            { 
                                                            case 2:H=((2/pi)*(exp(p*Q[Step_1])*Factor[Step_1]*sin(Q[Step_1]*r_))+(2/pi)*(exp(p*Q[Step_2])*Factor[Step_2]*sin(Q[Step_2]*r_)))/2*(Q[Step_2]-Q[Step_1]); break;
			                                          //    H=((2/pi)*(Factor[Step_1]*sin(Q[Step_1]*r)*exp(-Q[Step_1]*Q[Step_1]*PA))+(2/pi)*(Factor[Step_2]*sin(Q[Step_2]*r)*exp(-Q[Step_2]*Q[Step_2]*PA)))/2*(Q[Step_2]-Q[Step_1]);
		/*�۲�ó�ʹ��Hanning��Ҫ�˸�2*/                    case 1:H=2*((2/pi)*(exp(p*Q[Step_1])*Factor[Step_1]*0.5*(1-cos(2*pi*Step_1/(Step_Use+1)))*sin(Q[Step_1]*r_))+(2/pi)*(exp(p*Q[Step_2])*Factor[Step_2]*0.5*(1-cos(2*pi*Step_2/(Step_Use+1)))*sin(Q[Step_2]*r_)))/2*(Q[Step_2]-Q[Step_1]); break;
                                                            default: break;//��һ����������� Step_Number?      ���� 
                                                            }
                                                            G_=G_+H;
                                                         //   theta=theta+theta_step;                                                            
                                                            
                                                            Step_1=Step_1+1;
                                                            Step_2=Step_2+1;
                                                            }
                  
                                                            fprintf(output_pdf,"%lf\t%lf\n",r_,G_);
                                                            r_=r_+stepr;
                                                         
                                                          
                                             }
                                             fclose(output_pdf);
                                             }   
                                             r_=stepr;                                          

                                      
                                      //else
                                      if (k==2)
                                     {
                                          double density,g,RDF,D_RDF;
                                          printf("\nSo please input the average density of the sample(number/A^3).\n");
                                          scanf("%lf",&density);
                                          
                                          printf("\nRuning...\n\n");
                                          
                                         // fprintf(output_pdf,"r\tG\tg\tRDF\tD-RDF\n");
                                             // r=stepr;
                                             FILE *output_pdf=NULL;
                                             output_pdf=fopen("3.rPDF.txt","w");
                                             fprintf(output_pdf,"r\tG\tg\tRDF\tD-RDF\n");
                                            // rn=1;
                                              while(r_<=Rmax)
                                              {
                                                            G_=0;  
                                                         //   theta=theta_min;
                                                                                                                                                                                   
                                                            Step=1;
                                                            int Step_1,Step_2;
                                                            Step_1=1;
                                                            Step_2=2;          
                                                            while(Step_2<=Step_Use)
                                                            {
                                                            switch (Hanning)
                                                            { 
                                                            case 2:H=((2/pi)*(exp(p*Q[Step_1])*Factor[Step_1]*sin(Q[Step_1]*r_))+(2/pi)*(exp(p*Q[Step_2])*Factor[Step_2]*sin(Q[Step_2]*r_)))/2*(Q[Step_2]-Q[Step_1]); break;
			                                          //    H=((2/pi)*(Factor[Step_1]*sin(Q[Step_1]*r)*exp(-Q[Step_1]*Q[Step_1]*PA))+(2/pi)*(Factor[Step_2]*sin(Q[Step_2]*r)*exp(-Q[Step_2]*Q[Step_2]*PA)))/2*(Q[Step_2]-Q[Step_1]);
		/*�۲�ó�ʹ��Hanning��Ҫ�˸�2*/                    case 1:H=2*((2/pi)*(exp(p*Q[Step_1])*Factor[Step_1]*0.5*(1-cos(2*pi*Step_1/(Step_Use+1)))*sin(Q[Step_1]*r_))+(2/pi)*(exp(p*Q[Step_2])*Factor[Step_2]*0.5*(1-cos(2*pi*Step_2/(Step_Use+1)))*sin(Q[Step_2]*r_)))/2*(Q[Step_2]-Q[Step_1]); break;
                                                            default: break;//��һ����������� Step_Number?      ���� 
                                                            }
                                                            G_=G_+H;
                                                         //   theta=theta+theta_step;                                                            
                                                            
                                                            Step_1=Step_1+1;
                                                            Step_2=Step_2+1;
                                                            }
                                                            g=G_/4/pi/r_/density+1;
                                                            RDF=4*pi*r_*r_*density*g;
                  
                                                            fprintf(output_pdf,"%lf\t%lf\t%lf\t%lf\n",r_,G_,g,RDF);
                                                            r_=r_+stepr;
                                              }
                                             fclose(output_pdf);
                                              r_=stepr;           
 
                                   // printf("The current p is %lf.\nDo you want to try other the parameters to conduct the Laplace Tranform?\n1.Yes\t2.No\n",p);
                                    //scanf("%d",&CC);
                                    //if(CC==1)
                                    //         {
                                    //         printf("Input the p value (~0, do not use extreme values)\n");
                                    //         scanf("%lf",&p);
                                    //         }
                                    }
                   
                                      printf("Fourier Transform End\nDo you want to change the parameters of PDF?\n1.Yes\t2.No\n");
                                      scanf("%d",&i_i);
                                       while(i_i!=1&&i_i!=2)
                                        {
                                           printf("!!!Fourier Transform End\nDo you want to change the parameters of PDF?\n1.Yes\t2.No\n");
                                           scanf("%d",&i_i);
                                        }   
                                      }
                                      i_i=1;                                        
                                                          
                                                            
                       }  
                        
                        printf("\n\n\n----------\nDo you want to change the parameter N?\n1.yes\t2.no\n");
                        scanf("%d",&choice);
                        while(choice!=1&&choice!=2)
                                        {
                                           printf("\n\n\n----------\nDo you want to change the parameter N?\n1.yes\t2.no\n");
                                           scanf("%d",&choice);
                                        }   
                        
        }
        choice=1;     
    printf("Process End\n");
}

    getch();
    return 0;
    
}    
