#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ���༺ �ִ� �迭 ���, Flexible Array Members
//
// ����ü�� �迭 ����� ���༺ �ְ� ����ϴ� ����� ���� ���ڴ�. 
// �迭�� flexible �ϴٴ� ���� ���̰� ���� �� �ִٴ� ���̴�. 

int main() {
	/*
		Flexible array member (struct hack in GCC)
	*/

	struct flex {
		size_t count;
		double average;
		double values[];	// flexbile array member (last member!)
	};

	const size_t n = 3;

	struct flex* pf = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
	if (pf == NULL) exit(1);

	printf("\nFlexible array member\n");
	printf("Sizeof struct flex %zd\n", sizeof(struct flex));
	printf("Sizeof *pf %zd\n", sizeof(*pf));
	printf("Sizeof malloc %zd\n", sizeof(struct flex) + n * sizeof(double));
	printf("\n------------------------------\n");

	printf("%lld\n", (long long)pf);
	printf("%lld\n", (long long)&pf->count);
	printf("%zd\n", sizeof(pf->count));
	printf("%lld\n", (long long)&pf->average);
	printf("Address of pf->values %lld\n", (long long)&pf->values);
	printf("Value of pf->values %lld\n", (long long)pf->values);
	printf("Sizeof pf->values %zd\n", sizeof(pf->values));
	
	pf->count = n;
	pf->values[0] = 1.1;
	pf->values[1] = 2.1;
	pf->values[2] = 3.1;

	pf->average = 0.0;
	for (unsigned i = 0; i < pf->count; ++i)
		pf->average += pf->values[i];
	pf->average /= (double)pf->count;

	printf("Average = %f\n", pf->average);

	/*
	struct nonflex
	{
		size_t count;
		double average;
		double *values;		// Use malloc()
	};

	struct nonflex nf;
	nf.value = (double*)malloc(sizeof(double) *n); 
	*/

	/*
	struct flex* pf2 = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
	if (pf2 == NULL) exit(1);

	*pf2 = *pf1;	// Don't copy flexible members, use memcpy() instead

	free(pf);
	free(pf2);
	*/

	return 0;
}

// Flexible array member��,
// �������� GCC���� ���(struct hack in GCC)�̾��µ�, ǥ������ ��� �Դ�.
// 
// double values[];
// <= ������ ����� �迭�� ������ �ϴµ�, �迭�� ���� �� �����ϴ�. 
//    ���̰� ����. �ݵ�� ������ ������� �Ѵ�. 
//    �׸��� ���� �Ҵ��� �ؾ� �Ѵ�.
// 
// ���� ����ü�� ũ�⸸ŭ ���� �Ҵ��� �޴� �� �ƴϰ�, 
// ���� ����ϰ� ���� ���̸�ŭ �߰��� ���� �Ҵ��� �޴´�. 
// struct flex* pf = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
// <= n * sizeof(double) ��ŭ ���� �Ҵ��� �޴´�. 
// 
// �׷���, struct flex�� 
// size_t count;�� �ְ�, 
// double average;�� �ְ�,
// double values[]; <= �� �迭�� ����ϰ� ���� �޸�(���⿡���� 3ĭ)�� �ִ�. 
// 
// const size_t n = 3; n * sizeof(double)
// <= ���⿡���� double 3���� ������ �ִ� ���·� �޸𸮿� ������ �� ���̴�.
//  
// �׸��� ���� ���� �� ĭ�� values[]�� �迭ó�� ����� �� �ִ�. 
// 
// �ؿ� �ִ� ��� ������ ���� ���� ����.
// pf->count = n;
//  <= count���ٰ� �� �� �ִ��� ������ ���´�.  
//     �ֳ��ϸ�, ���� �Ҵ��� �޾ұ� ������, 
//     �� �� �Ҵ��� �ް� ���� ����� ������ �� ����.
//     �Ҵ� ���� ���Ŀ� count��� ������ �������ٰ� �� ĭ�� ���� �޾Ҵ��� 
//     ������ �� ���� ���� ����.  
// 
// pf->values[0] = 1.1;
// pf->values[1] = 2.1;
// pf->values[2] = 3.1;
//  <= values�� �̷��� �ʱ�ȭ�� �ϸ� �ȴ�. 
// 
// pf->average = 0.0;
// for (unsigned i = 0; i < pf->count; ++i)
//	   pf->average += pf->values[i];
// pf->average /= (double)pf->count;
// <= ��յ� �̷��� ���� �� �ִ�. 
//    �迭ó�� ����� �� �ֱ� ������ for���� ���� �� �ִ�. 
//    �� ������ count�� �־� ���� ���ڸ� �̿��ؼ� for���� �ۼ��� �� �ִ�. 
// 
// ��ġ ����ü �� �ڿ� �迭�� �ִµ�, 
// struct flex* pf = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
// <= �̷��� ���� �Ҵ��� �ޱ� ������ ���� �Ҵ� �迭ó�� ����� �� �ִ�. 
// 
// ���̰� �þ�� �پ����� �� �� �ִ�. 
// 
// const size_t n = 3;
// <= �� n ũ�⸦ �ٲٸ�, 
//    struct flex�� ��� double values[]; �迭�� ũ�⸦ �󸶵��� �ٲ� ���� �ִ�. 
// 
// ���ϰ� ����� �� �ִ� ���� �� �ϳ��̴�. 
// 
// �޸� ������ ��� �Ǵ��� ��ü���� ������ �ڵ� ���鼭 ������ ������ �ϰڴ�. 
// �� �ڵ带 ������ ����, 
// 
// printf("\nFlexible array member\n");
// printf("Sizeof struct flex %zd\n", sizeof(struct flex));
// <= ����� ��� ���� 16�̴�. 
//    struct flex�� ��� size_t�� ���콺�� ���� ���, 
//	  x64������ unsigned long long 8 ����Ʈ(x86������ unsigned int 4 ����Ʈ)�̴�.
//    �ٸ� ��� double average;�� 8 ����Ʈ,
//    double values[];�� ����� �󸶴���, 
//    sizeof(struct flex) struct flex�� ����� 16�� �� ���� ���� ���δ�. 
// 
// �Ʒ����� �ּҸ� ���� ����. 
// printf("%lld\n", (long long)pf);
//  <= ����ü ��ü�� �ּ� pf(pf ��ü�� �ּ��̴�)�� ��� ����, 
//     1894688684752 �� ���´�. (x64)   
// 
// printf("%lld\n", (long long)&pf->count);
//  <= �״���, ����ü�� ù ��° ����� �ּҸ� ��� ����, 
//     1894688684752 �� ����ü ��ü pf�� �ּҿ� �����ϴ�. 
// 
// printf("%zd\n", sizeof(pf->count));
//  <= ù ��° ����� �������, x64���� unsinged long long 8 ����Ʈ,
//     x86������ unsigned int 4 ����Ʈ�̴�. 
//     �ٽ� �� �� struct flex�� ��� size_t�� ���콺�� ���� �� ����, 
//     typedef unsinged long long size_t��� ���. 
//     <= typedef�� �̿��ؼ� unsigned long long�� size_t�� ����ϰ� �ִ� �����̴�.
//        �� �����Ϸ������� size_t�� unsigned long long�̶�� ���̴�. 
//        (x86������ size_t�� unsigned int�̴�)
// <= ���) ������� 8�� ���Դ�(x64). x86������ 4�� ���´�. 
// 
// printf("%lld\n", (long long)&pf->average);
// <= pf->average�� �ּҸ� ��� ����, 
//    1894688684760�� ���´�. 
//    pf->count�� ���۵Ǵ� �ּҷκ��� pf->average�� ���۵Ǵ� �ּ� ���̰�, 
//    pf->count�� �����ϰ� �ִ� �ּҰ� �ȴ�. 
// 
//    pf->count�� �ּҴ� 1894688684752�̰� 
//    pf->average�� �ּҴ� 1894688684760���� ���̴� 8�̴�. 
//    (x86������ 8�� ���̰� ����)
//    x86������ sizeof(pf->count)�� 4��� �ߴµ�, 
//    pf->count�� pf->average�� ���̴� �� 4�ΰ�?
//    <= padding�� �� ���̴�. (Allignment�� �� �ֱ� ���ؼ�)
//       �̰� �����Ϸ��� �������� ��, allignment struct memory, 
//       allignment option�� ���� �޶��� �� �ִ� ���̴�. 
// 
// �ϴ� padding�� �ϴ� ���� �Ϲ����̹Ƿ� x86������ 8����Ʈ�� ���̰� ���ٴ� ���� 
// ����� �ֶ�. 
// 
// size_t�� 8 ����Ʈ�̰�(x86������ 4 + 4(�е�)), pf->average�� 8 ����Ʈ�̴�.
// �׸��� Sizeof malloc 40���� �츮�� malloc���� ��û�� ���� 40�̴�. 
// 
// �׷� Sizeof struct flex�� 16�̶�� ����� ��� ���� ���ΰ�?
//   
// �Ʒ��� ���� ����,
// printf("Address of pf->values %lld\n", (long long)&pf->values);
// <= pf->values�� �ּڰ��� 1894688684768�̴�. 
//    pf->count�� �ּڰ�(1894688684752)���� ���̴� 16�̴�.  
// 
// printf("Value of pf->values %lld\n", (long long)pf->values);
// <= pf->values�� ������ �������̴�. (�迭�̹Ƿ�)
//    �迭�� ù ��° ���Ҹ� ����Ű�� �������̴�. 
//    
//    pf->values�� �ּҿ� pf->values�� ���� 
//    1894688684768���� �����ϴ�. 
// 
// printf("Sizeof pf->values %zd\n", sizeof(pf->values));
// <= �����Ϸ�(�������� ����ȯ��)�� ������ ���� ǥ�ø� �ؼ� ��� �� �ְ� �ִ�. 
//    ��� ���� 0�� ���´�. �� ����� 0�̴�. 
//    �̻��ϴ�. 
// 
// �޸𸮿� ���� �Ҵ��� �޴´�.  
// ���� 16�� size_t count�� double average�� �Ҵ��ϱ�� �� �־��µ�
// �ű⿡ ���� �Ҵ����� n * sizeof(double) ��ŭ�� �� �޾Ƽ�, 
// values[]�κ��� �����ϴ� �迭�� ����ϴ� ���̴�. 
// � �鿡���� ���� �Ҵ� �迭�� ����� ������ ����. 
// 
// ���� ������ �ִ�. 
// 
// ������ ����� double* values; <= �迭�� �ƴ� �����ͷ� �� ����, 
// nf.value = (double*)malloc(sizeof(double) * n); 
// <= �̷��� malloc���� ���� �Ҵ����� �߰��� �޴� �Ͱ� � ���̰� �ְڴ°�?
// 
	/*
	struct nonflex
	{
		size_t count;
		double average;
		double* values;		// Use malloc()
	};

	struct nonflex nf;
	nf.value = (double*)malloc(sizeof(double) * n);
	*/
// 
// <= ����ü nf�� ������� size_t�� �е��� ���� double average�� 8����Ʈ�̹Ƿ�,
//    16����Ʈ���ٰ� �߰��� double* values; x86�̸� �����Ͷ� 4����Ʈ, 
//    x64��� 8����Ʈ�� �� ���̴�. ���� �� 24����Ʈ�� �� ���̴�. 
// 
// nf.value = (double*)malloc(sizeof(double) * n);
// <= �� �޸𸮿� �� �� ���� ��� ���� ���� �Ҵ��� 
//    (double*)malloc(sizeof(double) * n); <= �̸�ŭ�� �ް�
//    �̰��� �迭�� ����� �� �ִ� ���� �Ҵ� �迭�� �ϳ� ���ܳ��� �����̴�. 
// 
// �׷� ���̰� �����ΰ�?
// struct nonflex�� ��� double* values;�� ������ ��ü�� �ּҸ� �� �����ϰ� �ִ�.
// 
// struct flex�� ��� double values[]�� �̰� ��ü�� �޸𸮸� ���������� �ʴ´�.
// ����ü�� �տ� �ִ� ��� �ڿ� ���� �Ҵ����� �޸𸮰� �߰��ż� �ٴ� �����̱� ������, 
// �̰��� �迭�� ����� �� �ִ� ������ values[] ��ü�� �޸𸮸� ���������� �ʴ´�.
// 
// �׷��� struct nonflex�� ��� double* values;�� �������̹Ƿ�, 
// ������ ��ü�� �޸𸮸� �����ϰ� �ִ�. <= ù ��° �����̴�. 
// 
// �� ��° ���̴�, 
// nf.value = (double*)malloc(sizeof(double) * n); �� ���� �Ҵ� �迭��, 
// �޸��� ��� ��ġ���� �� ���� ����. 
// ������,
// 
// struct flex�� ��� double values[]�� �߰��� �޴� �޸𸮴�
// (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
// <= sizeof(struct flex)���ٰ� + n * sizeof(double)�� �߰��� ���� ���̱� ������,
//    malloc()�� (sizeof(struct flex) + n * sizeof(double)) �����ŭ 
//    �Ͽ��� ������ �޸𸮸� �ش�. <= �׷��� ��� �ִ��� Ȯ���ϰ� �ȴ�. 
//    <= �Ͽ��� ������ �޸𸮸� �޴´ٴ� ���� ����϶�. 
// 
// �׷���,������ ����� flexbile array ����� �ƴ϶� ���� �Ҵ� �迭ó�� �����ͷ�
// ������ ���� �Ҵ��� ���� ��쿡�� ����ü struct nonflex�� �� ���� ����� �����ϴ�
// �޸𸮿� ������ ����� ����Ű�� �޸� (double*)malloc(sizeof(double) * n);��
// ������ ���� �ָ� ������ ���� �� �ִ�. 
// <= �޸� ������ �����ؼ� ������ �� �� �ִ� �����̴�. 
// 
// �� �ٸ� ���� ������ �ִ�. 
// 
// *pf2 = *pf1; <= �̷��� assignmnet�� �ϸ�, ���簡 �� �� �ȴ�. 
// �տ���
// printf("Sizeof struct flex %zd\n", sizeof(struct flex));
// <= struct flex�� ����� ��� ���ϱ� 16�̾���. 
// 
// ���� �Ҵ��� ���� ���� 40�̾��µ�, struct flex�� ������� 16�̾���. 
// �׷��Ƿ� �����Ϸ� ���忡����  *pf2 = *pf1; �̷��� ������ �õ����� ��, 
// 16����Ʈ�� ���縦 �� �ش�. �߰��� ��û�� 8 * 3 = 24����Ʈ�� ���簡 ���� �ʴ´�.
// 
// �����Ϸ� ���忡���� ���� �Ҵ����� �޾ƿԱ� ������ ����� �� ���� ����. 
// �׷��Ƿ�, 
// memcpy()�� ����ؼ� 
// struct flex* pf2 = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double)); �� �޸� ��ü�� memcpy()�� ���縦 �ϴ� �� ����. 
// <= �̷��� memcpy()�� ������ �ִ� �� flexible array memeber�� ����ϴ� 
//    �ǹٸ� ����̴�. 
// 
// flexible array member�� ���������� ���� �ô�. 