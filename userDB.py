import abc
from membershipEnum import MembershipEnum

DEFAULT_POINT = 10000

class NotExistedIDError(Exception):
    def __init__(self):
        super.__init__('존재하지 않는 ID입니다.')

class User:
    def __init__(self, id):
        self.id = id
        self.membership = MembershipEnum.BRONZE.value
        self.point = DEFAULT_POINT
        self.trade_cnt = 0

    def __repr__(self):
        return str(self.__dict__)


class UserDBInterface(metaclass=abc.ABCMeta):
    @abc.abstractmethod
    def __init__(self):
        """
        init
        """
        raise NotImplemented

    @abc.abstractmethod
    def addUser(self, id):
        """
        해당 id를 가지는 유저를 생성한다. ( 중복 검사 )
            param
                id: 유저의 id
            return
                True : 성공
                Fasle : 실패
        """
        raise NotImplemented

    @abc.abstractmethod
    def getInfo(self, id):
        """
        해당 id 를 가지는 유저 정보를 dict 형태로 반환합니다.
            param
                id 찾고자 하는 유저 id(PK)
            return
                유저 정보가 담긴 dictionary
        """
        raise NotImplemented

    @abc.abstractmethod
    def setPoint(self, id, newPoint):
        """
        해당 id 를 가지는 유저의 point 필드값을 newPoint로 수정합니다
            param
                id: 수정하고자 하는 유저의 id(PK)
                newPoint: point의 수정값
            return
                True: 성공
                False : 실패
        """
        raise NotImplemented

    @abc.abstractmethod
    def getAllInfo(self):
        """
        DB에 저장된 모든 User의 Info를 반환
            return
                모든 유저 정보가 담긴 list
        """
        raise NotImplemented

    @abc.abstractmethod
    def increaseTradeCnt(self, id):
        raise NotImplemented

    @abc.abstractmethod
    def getUserList(self):
        raise NotImplemented

    @abc.abstractmethod
    def setMembership(self, user_id, membership):
        raise NotImplemented

class UserDBImpl(UserDBInterface):
    def __init__(self):
        self.users = {}

    def addUser(self, id):
        if id in self.users: # id 중복
            print("ERROR already id exists")
            return False
        else:
            self.users[id] = User(id)
            print("create success")
            return True

    def getInfo(self, id):
        if id in self.users:
            return self.users[id].__dict__
        else:
            raise NotExistedIDError
        
    def setPoint(self, id, newPoint):
        if id in self.users:
            self.users[id].point = newPoint
            return True
        else:
            raise NotExistedIDError

    def getAllInfo(self):
        return list(self.users.values())

    def increaseTradeCnt(self, id):
        if id in self.users:
            self.users[id].trade_cnt += 1
            return True
        else:
            raise NotExistedIDError

    def getUserList(self):
        l = []
        for key in self.users:
            l.append(self.getInfo(key))
        return l

    def setMembership(self, user_id, membership):
        self.users[user_id].membership = membership