# 42_factorization by jjo

### 1. test 과정

- #### 시간 복잡도 줄이기

  - 초기 알고리즘

    ```c
    void	ft_factorization(unsigned int num)
    {
    	unsigned int	i;
    
    	i = 2;
    	while (num != 1)
    	{
    		if(num % i == 0)
    		{
    			while(num % i == 0)
    				num = num / i;
    			printf("%u", i);
    			if(num != 1)
    				printf(" ");
    		}
    	}
    	printf("\n");
    }
    ```

    > 문제점 : 값이 큰 소수의 경우는 10초 이상 소요 됨 (시간 복잡도 : O(n))

  - 개선 알고리즘

    ```c
    void	ft_factorization(unsigned int num)
    {
    	unsigned int	i;
    
    	i = 2;
    	if(is_prime(num))
    	{
    		printf("%u\n", num);
    		return;
    	}
    	while (num != 1)
    	{
    		if(num % i == 0)
    		{
    			while(num % i == 0)
    				num = num / i;
    			printf("%u", i);
    			if(num != 1)
    				printf(" ");
    			if(is_prime(num))
    			{
    				printf("%u", num);
    				break;
    			}
    		}
    		i++;
    	}
    	printf("\n");
    }
    ```

    `num`의 값이 갱신 될때 마다 해당 값이 소수인지 확인함(`에라토스테네스의 체` 사용 )

    단순한 이론상으론  여전히 시간 복잡도 : O(n) 처럼 보이지만, 소수를 미리 체크할 수 있기 때문에 훨씬 효율적임 (1초 이내로 범위내의 모든 결과 값을 구할 수 있음)

- #### 범위 예외 처리

  - 문자열을 숫자로 변환하는 과정에서 `unsigned int`로 반환하게 되면 오버플로우를 감지 하지 못해서 범위 초과를 감지하지 못한다. 그래서 변환하는 함수의 반환 타입을  `unsigned long long` 으로 해주었다.

    ```c
    unsigned long long	ft_atoull(const char *num_str)
    ```

  - 하지만, `unsigned long long`도 엄청 큰 값이 입력되면 오버플로우가 발생할 수 있어, 이때의 오버플로우를 사전에 차단하기 위해 인자로 받은 문자열의 길이가 10(`+`부호가 있는 경우는 11)이 넘을 경우는 범위를 넘었다고 판단하게 처리하였다.

    ```c
    // int digit_check(char *str) 함수 中
    
    if(i > 10 || (str[0] == '+' && i > 11))
        return (-2);
    ```

    

### 2. 예외처리 결과

1. 인자 개수 체크

   - 인자가 하나가 아닌 경우 error message 출력 후 종료 

     ![image](https://user-images.githubusercontent.com/53181778/78229576-b572da00-74bf-11ea-9641-ea103481e46b.png)

2. 유효성 체크

   - 인자가 양의 정수로 되어 있는지 체크 후 음수나 숫자이외의 값이 들어 있으면 error message 출력 후 종료 

     ![image](https://user-images.githubusercontent.com/53181778/78229513-9ffdb000-74bf-11ea-8269-b80467f57306.png)

3. 범위 체크

   - 인자가 2 ~ 2<sup>32</sup> -1 의 범위에 있지 않으면, error message 출력 후 종료 

     ![image](https://user-images.githubusercontent.com/53181778/78229666-d76c5c80-74bf-11ea-942d-6359be7e6e2d.png)